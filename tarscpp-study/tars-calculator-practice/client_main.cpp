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

        const tars::Int32 left = 12;               // 定义第一个操作数
        const tars::Int32 right = 30;              // 定义第二个操作数

        const tars::Int32 addResult =             // 保存加法结果
    proxy->add(left, right);               // 通过 RPC 调用加法

        const tars::Int32 subtractResult =        // 保存减法结果
    proxy->subtract(right, left);          // 通过 RPC 调用减法

        const tars::Int32 multiplyResult =        // 保存乘法结果
    proxy->multiply(left, right);          // 通过 RPC 调用乘法

        const tars::Int32 divideResult =          // 保存除法结果
    proxy->divide(right, left);            // 通过 RPC 调用除法

        std::cout << left                         // 输出加法左操作数
          << " + "
          << right                        // 输出加法右操作数
          << " = "
          << addResult                    // 输出加法结果
          << std::endl;

        std::cout << right                        // 输出减法左操作数
          << " - "
          << left                         // 输出减法右操作数
          << " = "
          << subtractResult               // 输出减法结果
          << std::endl;

        std::cout << left                         // 输出乘法左操作数
          << " * "
          << right                        // 输出乘法右操作数
          << " = "
          << multiplyResult               // 输出乘法结果
          << std::endl;

        std::cout << right                        // 输出除法左操作数
          << " / "
          << left                         // 输出除法右操作数
          << " = "
          << divideResult                 // 输出除法结果
          << std::endl;

          const tars::Int32 zeroDivideResult =      // 保存除数为零时的返回值
    proxy->divide(10, 0);                 // 调用 divide(10, 0)

        std::cout << "10 / 0 = "                     // 输出测试说明
          << zeroDivideResult             // 输出服务端返回值
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