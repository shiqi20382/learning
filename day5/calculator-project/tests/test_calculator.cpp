#include "calculator.h"                      // 引入 Calculator 类
#include <cassert>                            // 引入断言功能
#include <iostream>                           // 引入输出功能
#include <cmath>                              // 引入 fabs
#include <exception>                          // 引入异常类型

int main()                                  // 测试程序入口
{
    Calculator calc;                   // 创建 Calculator 对象

    assert(calc.add(2, 3) == 5);        // 测试 2 + 3 = 5
    assert(calc.subtract(8, 3) == 5);   // 测试 8 - 3 = 5
    assert(calc.multiply(4, 5) == 20);  // 测试 4 * 5 = 20
    assert(std::fabs(calc.divide(10, 2) - 5.0) < 1e-9); // 测试 10 / 2 = 5

    bool caught = false;                      // 记录是否捕获除零异常

    try                                     // 尝试执行除零操作
    {
        calc.divide(10, 0);             // 除数为 0，应抛出异常
    }
    catch (const std::invalid_argument&)    // 捕获除数为 0 的异常
    {
        caught = true;                        // 标记异常已捕获
    }

    assert(caught);                           // 确认除零异常确实被捕获

    std::cout << "所有测试通过" << std::endl;  // 输出测试成功信息

    return 0;                                 // 测试程序正常结束
}