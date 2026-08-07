cmake_minimum_required(VERSION 3.10)          # 指定 CMake 最低版本

project(CalculatorProject LANGUAGES CXX)      # 定义项目名称并启用 C++

set(CMAKE_CXX_STANDARD 11)                    # 使用 C++11 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)            # 必须支持 C++11

add_library(calculator STATIC                 # 创建名为 calculator 的静态库
    src/calculator.cpp                         # 静态库的源文件
)

target_include_directories(calculator PUBLIC  # 配置头文件搜索路径
    ${CMAKE_CURRENT_SOURCE_DIR}/include        # 添加 include 目录
)

add_executable(calculator_app                 # 创建主程序
    src/main.cpp                               # 主程序源文件
)

target_link_libraries(calculator_app PRIVATE  # 链接 calculator 静态库
    calculator                                  # 指定要链接的库
)
include(CTest)
enable_testing()                               # 启用 CTest 测试功能

add_executable(calculator_test                # 创建测试程序
    tests/test_calculator.cpp                  # 测试源文件
)

target_link_libraries(calculator_test PRIVATE  # 测试程序链接静态库
    calculator                                  # 指定要链接的库
)

add_test(                                      # 注册一个 CTest 测试
    NAME calculator_test                        # 测试名称
    COMMAND $<TARGET_FILE:calculator_test>                    # 测试执行的程序
)