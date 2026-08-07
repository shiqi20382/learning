#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include <vector>
#include "employee.h"

class EmployeeManager {
private:
    std::vector<Employee> employees_;

public:
    void addEmployee(const Employee& emp);
    void printAllEmployees() const;
    Employee* findEmployeeById(int id);
};

#endif // EMPLOYEE_MANAGER_H