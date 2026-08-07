#include"employeemanager.h"

void EmployeeManager::addEmployee(const Employee& employee) {
    employees_.push_back(employee);
}

Employee* EmployeeManager::findEmployeeById(int id) {
    for (auto& employee : employees_) {
        if (employee.getId() == id) {
            return &employee;
        }
    }
    return nullptr; // Return nullptr if not found
}

void EmployeeManager::printAllEmployees() const {
    for (const auto& employee : employees_) {
        employee.printInfo();
    }
}   