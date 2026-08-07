#include"employeemanager.h"
#include <iostream>

int main(){

    EmployeeManager manager;

    // Adding employees
    manager.addEmployee(Employee("石器时代", 1, 30));
    manager.addEmployee(Employee("王沛帆", 2, 25));
    manager.addEmployee(Employee("bedivere", 3, 28));

    // Displaying all employees
    std::cout << "All Employees:" << std::endl;
    manager.printAllEmployees();

    // Searching for an employee by ID
    int searchId = 1;
    Employee* employee = manager.findEmployeeById(searchId);
    if (employee) {
        std::cout << "\nEmployee found with ID " << searchId << ":" << std::endl;
        employee->printInfo();
    } else {
        std::cout << "\nNo employee found with ID " << searchId << "." << std::endl;
    }

    return 0;   
}