#include "CalculatorImp.h"

void CalculatorImp::initialize()
{}

void CalculatorImp::destroy()
{}

tars::Int32 CalculatorImp::add(
    tars::Int32 left,
    tars::Int32 right,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    return left + right;
}

tars::Int32 CalculatorImp::subtract(
    tars::Int32 left,
    tars::Int32 right,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    return left - right;
}

tars::Int32 CalculatorImp::multiply(
    tars::Int32 left,
    tars::Int32 right,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    return left * right;
}

tars::Int32 CalculatorImp::divide(
    tars::Int32 left,
    tars::Int32 right,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    if(right == 0)
    {
        return -1;
    }

    return left / right;
}

MathApp::CalculatorResult CalculatorImp::calculate(
    const  MathApp::CalculatorRequest& request,
    tars::TarsCurrentPtr current
)
{
    (void)current;

    MathApp::CalculatorResult result;

    result.value = request.left + request.right;

    result.message = "calculate success";

    return result; 
}

std::vector<tars::Int32> CalculatorImp::batchAdd(
    const std::vector<tars::Int32>& values,
    tars::Int32 increment,
    tars::TarsCurrentPtr current
)
{
    (void)current;                            // 当前不使用请求上下文

    std::vector<tars::Int32> results;
    // 创建结果列表

    for (tars::Int32 value : values)
    // 逐个遍历客户端传入的整数
    {
        results.push_back(value + increment);
        // 将增加 increment 后的结果放入列表
    }

    return results;                            // 返回结果列表
}

std::map<std::string, tars::Int32> CalculatorImp::countByName(
    const std::vector<std::string>& names,
    tars::TarsCurrentPtr current
)
{
    (void)current;                            // 当前不使用请求上下文

    std::map<std::string, tars::Int32> counts;
    // 创建姓名到次数的映射

    for (const std::string& name : names)
    // 逐个遍历姓名列表
    {
        counts[name] += 1;
        // 当前姓名出现次数加一
    }

    return counts;                             // 返回统计结果
}