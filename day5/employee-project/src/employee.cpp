#include"employee.h"
#include <iostream>

Employee::Employee(const std::string& n, int i, int a)
    : name_(n), id_(i), age_(a) {}

void Employee::printInfo() const {
    std::cout << "Employee Name: " << name_ << std::endl;
    std::cout << "Employee ID: " << id_ << std::endl;
    std::cout << "Employee Age: " << age_ << std::endl;
}

int Employee::getId() const {
    return id_;
}

std::string Employee::getName() const {
    return name_;
}   