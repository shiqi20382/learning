#include <iostream> // 提供标准输出功能

#include "HelloImp.h" // 引入手写服务端实现类

int main() // 定义程序入口
{
    HelloImp service; // 创建业务服务对象

    std::string result = service.sayHello( // 直接调用业务方法
        "石器时代", // 模拟客户端传入的姓名
        tars::TarsCurrentPtr() // 没有真实请求时传入空上下文
    );

    std::cout << result << std::endl; // 输出返回结果

    return 0; // 正常结束程序
}
