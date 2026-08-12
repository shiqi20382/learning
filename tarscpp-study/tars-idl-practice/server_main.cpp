#include <exception>
#include "HelloImp.h"
#include <iostream>
#include "servant/Application.h"

class HelloServer : public tars::Application
{
public:
    void initialize() override{
        addServant<HelloImp>(
            tars::ServerConfig::Application
            + "."
            + tars::ServerConfig::ServerName
            + ".HelloObj"
        );
    }

    void destroyApp() override
    {

    }
};

HelloServer g_app;   

int main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (const std::exception& exception)
    {
        std::cerr
            << "HelloServer启动失败:"
            << exception.what()
            << std::endl;

        return 1;
    }

    return 0;
}