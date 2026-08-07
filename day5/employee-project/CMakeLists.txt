cmake_minimum_required(VERSION 3.10)                  # 指定 CMake 最低版本

project(EmployeeProject LANGUAGES CXX)                # 定义项目名称，并启用 C++ 语言

set(CMAKE_CXX_STANDARD 11)                            # 指定使用 C++11 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)                   # 要求编译器必须支持 C++11

add_library(employee_lib STATIC                       # 创建名为 employee_lib 的静态库
    src/employee.cpp                                  # 将 Employee.cpp 加入静态库
    src/employeemanager.cpp                           # 将 EmployeeManager.cpp 加入静态库
)

target_include_directories(employee_lib PUBLIC        # 为静态库配置头文件搜索路径
    ${PROJECT_SOURCE_DIR}/include                     # 指定项目根目录下的 include 目录
)

add_executable(employee_app                           # 创建名为 employee_app 的可执行程序
    src/main.cpp                                      # 将 main.cpp 加入主程序
)

target_link_libraries(employee_app PRIVATE            # 将主程序链接到 employee_lib 静态库
    employee_lib                                      # 要链接的静态库名称
)