#include <exception>                         // 提供 std::exception
#include <iostream>                          // 提供 std::cerr

#include "servant/Application.h"             // 引入 Tars 服务端应用类
#include "CalculatorImp.h"                   // 引入计算器业务实现

class CalculatorServer : public tars::Application
{
     public:
     void initialize() override 
     {
        addServant<CalculatorImp>(            // 注册计算器业务实现
            tars::ServerConfig::Application  // 读取配置中的应用名
            + "."                            // 添加名称分隔符
            + tars::ServerConfig::ServerName // 读取配置中的服务名
            + ".CalculatorObj"               // 设置对象名称
        );
     }

     void destroyApp() override  
     {}

};

CalculatorServer g_app;

int main(int argc, char* argv[])
{
    try                                      // 捕获启动过程中的异常
    {
        g_app.main(argc, argv);               // 读取配置并初始化服务
        g_app.waitForShutdown();              // 持续等待客户端请求
    }
    catch (const std::exception& exception)   // 捕获标准异常
    {
        std::cerr                             // 输出启动失败原因
            << "CalculatorServer 启动失败: "
            << exception.what()
            << std::endl;

        return 1;   
    }

    return 0;
}