cmake_minimum_required(VERSION 3.16) # 要求最低 CMake 版本

project(TarsIdlPractice LANGUAGES CXX) # 定义项目名称并启用 C++ 语言

set(CMAKE_CXX_STANDARD 14) # 使用 C++14 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制要求编译器支持 C++14
set(CMAKE_CXX_EXTENSIONS OFF) # 不使用编译器特有的 C++ 扩展

set(TARSCPP_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../TarsCpp") # 定义 TarsCpp 源码目录
set(TARSCPP_BUILD "${TARSCPP_ROOT}/build") # 定义已编译 TarsCpp 的构建目录

find_package(Threads REQUIRED) # 查找 Linux 线程库
find_package(ZLIB REQUIRED) # 查找 zlib 压缩库

add_executable(hello_local # 创建名为 hello_local 的可执行程序
    main.cpp # 加入程序入口文件
    service/HelloImp.cpp # 加入手写的服务端业务实现文件
)

target_include_directories(hello_local PRIVATE # 添加当前程序需要的头文件目录
    "${CMAKE_CURRENT_SOURCE_DIR}/generated" # 自动生成的 Hello.h 所在目录
    "${CMAKE_CURRENT_SOURCE_DIR}/service" # 手写的 HelloImp.h 所在目录
    "${TARSCPP_ROOT}/servant" # servant、tup、promise 等 TarsCpp 头文件的根目录
    "${TARSCPP_ROOT}/util/include" # util/tc_platform.h 等工具头文件目录
)

target_link_libraries(hello_local PRIVATE # 链接编译好的 TarsCpp 静态库和系统依赖
    "${TARSCPP_BUILD}/lib/libtarsservant.a" # Tars 服务端核心库
    "${TARSCPP_BUILD}/lib/libtarsutil.a" # Tars 通用工具库
    "${TARSCPP_BUILD}/lib/libtarsparse.a" # Tars 配置与协议解析库
    ZLIB::ZLIB # 链接 zlib
    Threads::Threads # 链接 pthread 线程库
    ${CMAKE_DL_LIBS} # 链接 dl 动态加载库
)
