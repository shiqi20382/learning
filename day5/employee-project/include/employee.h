#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name_;
    int id_;
    int age_;

public:
    Employee(const std::string& n, int i, int a);
    void printInfo() const;
    int getId() const;
    std::string getName() const;

};  

#endif 