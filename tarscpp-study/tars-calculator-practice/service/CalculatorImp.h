#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Calculator.h"
#include <map>                                  
#include <string>                              
#include <vector>                              


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
    

    std::vector<tars::Int32> batchAdd(
        const std::vector<tars::Int32>& values,
        tars::Int32 increment,
        tars::TarsCurrentPtr current
    ) override;
    

    std::map<std::string, tars::Int32> countByName(
        const std::vector<std::string>& names,
        tars::TarsCurrentPtr current
    ) override;
    

};
#endif