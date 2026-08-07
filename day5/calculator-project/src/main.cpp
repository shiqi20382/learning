#include"calculator.h"
#include <iostream>
#include <exception>

int main() {
    Calculator calc;
    double a;                                  
    double b;                                  
    
    std::cout << "请输入两个数：";         
    std::cin >> a >> b;                    

    std::cout << "Addition: " << calc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(a, b) << std::endl;
    std::cout << "Division: " << calc.divide(a, b) << std::endl;

    return 0;
}   