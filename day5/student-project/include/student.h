#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& name, int age);
    void printinfo() const;
private:
    std::string name;
    int age;
}; 
#endif // STUDENT_H