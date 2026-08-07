#include"student.h"
#include <iostream>
using namespace std;

Student::Student(const std::string& name, int age) : name_(name), age_(age) {}

void Student::printinfo() const {
    cout << "Name: " << name_ << ", Age: " << age_ << endl;
}