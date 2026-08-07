cmake_minimum_required(VERSION 3.10)              # 指定 CMake 最低版本

project(StudentApp LANGUAGES CXX)                 # 定义项目名称，并启用 C++

set(CMAKE_CXX_STANDARD 11)                        # 使用 C++11 标准

set(CMAKE_CXX_STANDARD_REQUIRED ON)               # 要求编译器必须支持 C++11

add_executable(student_app                        # 定义最终生成的可执行程序名称
    src/main.cpp                                   # 添加主程序源文件
    src/student.cpp                                # 添加 Student 类实现文件
)

target_include_directories(student_app PRIVATE    # 为 student_app 添加头文件搜索目录
    include                                        # 让代码可以找到 include/ 下的头文件
)