cmake_minimum_required(VERSION 3.10)                 # 指定 CMake 最低版本

project(BookProject LANGUAGES CXX)                   # 定义项目名称，并启用 C++ 语言

set(CMAKE_CXX_STANDARD 11)                           # 使用 C++11 标准

set(CMAKE_CXX_STANDARD_REQUIRED ON)                  # 要求编译器必须支持 C++11

add_library(book_lib STATIC                          # 创建名为 book_lib 的静态库
    src/Book.cpp                                     # 将 Book.cpp 编译进静态库
    src/BookManager.cpp                              # 将 BookManager.cpp 编译进静态库
)

target_include_directories(book_lib PUBLIC           # 为静态库指定头文件搜索路径
    ${PROJECT_SOURCE_DIR}/include                    # 指向项目根目录下的 include 文件夹
)

target_compile_options(book_lib PRIVATE              # 为 book_lib 开启常用编译警告
    -Wall                                            # 开启常用警告
    -Wextra                                          # 开启额外警告
)

add_executable(book_app                              # 创建名为 book_app 的可执行程序
    src/main.cpp                                     # 将 main.cpp 加入主程序
)

target_link_libraries(book_app PRIVATE               # 将主程序链接到静态库
    book_lib                                         # 指定链接 book_lib
)