cmake_minimum_required(VERSION 3.16)
project(HelloStaticLibrary LANGUAGES CXX)
add_library(
    greeter
    STATIC
    greeter/src/greeter.cpp
)
target_include_directories(
    greeter
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/greeter/include
)
add_executable(
    hello_static
    app/src/main.cpp
)
target_link_libraries(
    hello_static
    PRIVATE
    greeter
)