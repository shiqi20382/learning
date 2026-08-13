#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Calculator.h"
#include <map>                                  // 引入 std::map
#include <string>                              // 引入 std::string
#include <vector>                              // 引入 std::vector


class CalculatorImp : public MathApp::Calculator
{
    public:
    void initialize() override;

    void destroy() override;

    tars::Int32 add(                        
        tars::Int32 left,                  
        tars::Int32 right,                  
        tars::TarsCurrentPtr current         
    ) override;        
    
    tars::Int32 subtract(                        
        tars::Int32 left,                  
        tars::Int32 right,                  
        tars::TarsCurrentPtr current         
    ) override;

    tars::Int32 multiply(                        
        tars::Int32 left,                  
        tars::Int32 right,                  
        tars::TarsCurrentPtr current         
    ) override;

    tars::Int32 divide(                        
        tars::Int32 left,                  
        tars::Int32 right,                  
        tars::TarsCurrentPtr current         
    ) override;
    
    MathApp::CalculatorResult calculate(
        const MathApp::CalculatorRequest& request,
        tars::TarsCurrentPtr current
    ) override;
    // 接收计算请求结构体并返回计算结果结构体

    std::vector<tars::Int32> batchAdd(
        const std::vector<tars::Int32>& values,
        tars::Int32 increment,
        tars::TarsCurrentPtr current
    ) override;
    // 给整数列表中的每个元素增加 increment

    std::map<std::string, tars::Int32> countByName(
        const std::vector<std::string>& names,
        tars::TarsCurrentPtr current
    ) override;
    // 统计每个姓名出现的次数

};
#endif