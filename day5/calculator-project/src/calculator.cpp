#include"calculator.h"
#include <iostream>
#include <stdexcept>

Calculator::Calculator() : result(0) {}

double Calculator::add(double a, double b) {
    result = a + b;
    return result;
}

double Calculator::subtract(double a, double b) {
    result = a - b;
    return result;
}

double Calculator::multiply(double a, double b) {
    result = a * b;
    return result;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division by zero is not allowed.");
        return 0;
    }
    result = a / b;
    return result;
}   