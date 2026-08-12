cmake_minimum_required(VERSION 3.16)
project(HelloMultiFile LANGUAGES CXX)
add_executable(
    hello_multifile
    src/main.cpp
    src/greeter.cpp
)
target_include_directories(
    hello_multifile
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)