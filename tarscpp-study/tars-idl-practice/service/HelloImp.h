#ifndef HELLO_IMP_H // 防止头文件被重复包含
#define HELLO_IMP_H // 定义头文件保护宏

#include "Hello.h" // 引入 tars2cpp 自动生成的服务端接口

class HelloImp : public HelloApp::Hello // 继承自动生成的 Hello 服务端接口
{
public:
    void initialize() override; // 服务启动时由 Tars 框架调用一次

    void destroy() override; // 服务停止时由 Tars 框架调用一次

    std::string sayHello( // 重写 Hello.tars 中定义的 RPC 方法
        const std::string& name, // 接收客户端传入的姓名
        tars::TarsCurrentPtr current // 接收当前请求的上下文信息
    ) override; // 声明这是对父类虚函数的重写
};

#endif // HELLO_IMP_H
