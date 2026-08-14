#include <condition_variable>                // 提供条件变量，用于等待异步回调
#include <exception>                         // 提供 std::exception
#include <iostream>                          // 提供 std::cout 和 std::cerr
#include <mutex>                             // 提供 std::mutex 和 std::lock_guard
#include <string>                            // 提供 std::string
#include <chrono>

#include "servant/Communicator.h"             // 提供 Tars 客户端通信器
#include "Calculator.h"                      // 提供 CalculatorPrx 和回调基类

class AddCallback : public MathApp::CalculatorPrxCallback
// 定义 add 方法的异步回调类
{
public:
    void callback_add(tars::Int32 ret) override
    // 服务端成功返回时，Tars 框架调用此函数
    {
        {
            std::lock_guard<std::mutex> lock(_mutex);
            // 加锁，保护回调结果和完成状态

            _result = ret;
            // 保存服务端返回的加法结果

            _success = true;
            // 标记 RPC 调用成功

            _done = true;
            // 标记异步请求已经完成
        }

        _condition.notify_one();
        // 唤醒正在 wait() 中等待的客户端主线程
    }

    void callback_add_exception(tars::Int32 ret) override
    // RPC 调用失败时，Tars 框架调用此函数
    {
        {
            std::lock_guard<std::mutex> lock(_mutex);
            // 加锁，保护错误码和完成状态

            _errorCode = ret;
            // 保存 Tars 返回的错误码

            _success = false;
            // 标记 RPC 调用失败

            _done = true;
            // 标记异步请求已经完成
        }

        _condition.notify_one();
        // 唤醒正在等待的客户端主线程
    }

    bool waitForResult(int timeoutSeconds)
 // 等待异步请求完成，最多等待指定秒数
{
    std::unique_lock<std::mutex> lock(_mutex);
    // 使用 unique_lock，让条件变量能够临时释放互斥锁

    return _condition.wait_for(
        lock,
        std::chrono::seconds(timeoutSeconds),
        [this]()
        {
            return _done;
            // 回调完成后 _done 为 true，等待立即结束
        }
    );
    // 回调及时完成则返回 true，等待超时则返回 false
}

    bool success() const
    // 返回本次 RPC 是否成功
    {
        return _success;
        // 返回成功状态
    }

    tars::Int32 result() const
    // 返回服务端计算结果
    {
        return _result;
        // 返回保存的 add 结果
    }

    tars::Int32 errorCode() const
    // 返回失败时的 Tars 错误码
    {
        return _errorCode;
        // 返回保存的错误码
    }

private:
    mutable std::mutex _mutex;
    // 保护回调对象中的共享状态

    std::condition_variable _condition;
    // 用于通知主线程异步请求完成

    bool _done = false;
    // 标记异步请求是否已经完成

    bool _success = false;
    // 标记异步请求是否成功

    tars::Int32 _result = 0;
    // 保存服务端返回的整数结果

    tars::Int32 _errorCode = 0;
    // 保存 Tars 返回的错误码
};

int main()
// 定义异步客户端程序入口
{
    try
    // 捕获创建通信器或发起 RPC 时的异常
    {
        tars::Communicator communicator;
        // 创建 Tars 客户端通信器

        MathApp::CalculatorPrx proxy;
        // 声明 Calculator 客户端代理

        const std::string objectAddress =
            "MathApp.CalculatorServer.CalculatorObj"
            "@tcp -h 127.0.0.1 -p 29999";
        // 设置服务对象名称和服务端地址

        communicator.stringToProxy(
            objectAddress,
            proxy
        );
        // 根据对象地址创建 CalculatorPrx

        proxy->tars_set_timeout(3000);
// 设置 RPC 超时为 3 秒

        MathApp::CalculatorPrxCallbackPtr callback(
            new AddCallback()
        );
        // 创建异步回调对象，并保存为 Tars 回调指针

        proxy->async_add(
            callback,
            12,
            30
        );
        // 发起异步 add(12, 30) 请求；该调用本身没有直接返回结果

        AddCallback* callbackObject =
            dynamic_cast<AddCallback*>(callback.get());
        // 取出回调对象，便于等待和读取结果

        const bool completed =
    callbackObject->waitForResult(5);
// 最多等待 5 秒，避免客户端无限阻塞

if (!completed)
// 5 秒内没有收到成功或异常回调
{
    std::cerr
        << "等待异步 RPC 结果超时"
        << std::endl;
    // 输出本地等待超时信息

    return 1;
    // 返回 1，表示本次测试失败
}

        if (callbackObject->success())
        // 判断异步调用是否成功
        {
            std::cout
                << "12 + 30 = "
                << callbackObject->result()
                << std::endl;
            // 输出服务端返回的结果
        }
        else
        {
            std::cerr
                << "异步 add 调用失败,Tars 返回码: "
                << callbackObject->errorCode()
                << std::endl;
            // 输出 Tars 错误码
        }

        return callbackObject->success() ? 0 : 1;
        // 成功返回 0，失败返回 1
    }
    catch (const std::exception& exception)
    // 捕获发起请求前发生的 C++ 异常
    {
        std::cerr
            << "异步客户端启动失败: "
            << exception.what()
            << std::endl;
        // 输出异常原因

        return 1;
        // 返回 1 表示客户端失败
    }
}