cmake_minimum_required(VERSION 3.10)

project(StudentAPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_app
    src/main.cpp
    src/Student.cpp
)