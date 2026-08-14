#include <exception>                         // 提供 std::exception
#include <iostream>                          // 提供标准输出和错误输出
#include <string>                            // 提供 std::string

#include "servant/Communicator.h"            // 提供 Tars 客户端通信器
#include "Hello.h"                           // 提供自动生成的 HelloPrx

int main()                                   // 定义客户端程序入口
{
    try                                      // 捕获 RPC 调用期间的异常
    {
        tars::Communicator communicator;      // 创建 Tars 客户端通信器

        HelloApp::HelloPrx proxy;             // 声明 Hello 客户端代理

        const std::string objectAddress =     // 定义服务对象及网络地址
            "HelloApp.HelloServer.HelloObj"
            "@tcp -h 192.168.16.203 -p 22961";

        communicator.stringToProxy(           // 根据对象地址创建代理
            objectAddress,                    // 传入完整服务对象地址
            proxy                             // 保存创建好的 HelloPrx
        );

        const std::string result =            // 保存服务端返回结果
            proxy->sayHello("石器时代");       // 通过网络调用 RPC 方法

        std::cout                             // 输出 RPC 调用结果
            << result
            << std::endl;

        return 0;                             // 返回 0，表示调用成功
    }
    catch (const std::exception& exception)   // 捕获标准和 Tars 异常
    {
        std::cerr                             // 输出调用失败原因
            << "调用 Hello RPC 失败: "
            << exception.what()
            << std::endl;

        return 1;                             // 返回 1，表示调用失败
    }
}