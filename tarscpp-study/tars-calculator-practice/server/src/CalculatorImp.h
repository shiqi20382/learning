#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Calculator.h"

class CalculatorImp : public MathApp::Calculator
{
    public:
    void initialize() override;

    void destroy() override;

    tars::Int32 add(                        // 重写 IDL 中定义的 add 方法
        tars::Int32 left,                   // 接收第一个整数
        tars::Int32 right,                  // 接收第二个整数
        tars::TarsCurrentPtr current         // 接收当前 RPC 请求上下文
    ) override;                             // 让编译器检查重写签名
};
#endif