#include <exception>
#include <iostream>
#include <string>

#include "Calculator.h"
#include "servant/Communicator.h"

int main()
{
    try
    {
       tars::Communicator Communicator;
       MathApp::CalculatorPrx proxy;
       const std::string objectAddress = 
            "MathApp.CalculatorServer.CalculatorObj"
            "@tcp -h 127.0.0.1 -p 20002";

            Communicator.stringToProxy(
                objectAddress,
                proxy
            );

        const tars::Int32 left = 12;
        const tars::Int32 right = 30;

        const tars::Int32 result =
        proxy->add(left, right);

        std::cout
            << left
            << "+"
            << right
            << "="
            << result
            << std::endl;

        return 0;
    }
    catch(const std::exception& exception)
    {
        std::cerr
        << "调用Calculator RPC 失败："
        << exception.what()
        << std::endl;

    return 1;
    }
    
}