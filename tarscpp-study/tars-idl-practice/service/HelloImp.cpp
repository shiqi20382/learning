#include "HelloImp.h" // 引入 HelloImp 类的声明

void HelloImp::initialize() // 实现服务启动生命周期方法
{
    // 当前练习没有启动时需要执行的操作
}

void HelloImp::destroy() // 实现服务停止生命周期方法
{
    // 当前练习没有停止时需要执行的操作
}

std::string HelloImp::sayHello( // 定义 HelloImp 的 sayHello 方法
    const std::string& name, // 接收客户端传来的姓名
    tars::TarsCurrentPtr current // 接收请求上下文
)
{
    (void)current; // 当前练习不使用上下文，避免编译器提示未使用
    return "Hello, " + name + "!"; // 返回业务处理结果
}
