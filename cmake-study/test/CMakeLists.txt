cmake_minimum_required(VERSION 3.16)
project(CMakeFinalCheck LANGUAGES CXX)
add_library(
    message
    STATIC
    src/message.cpp
)
target_include_directories(
    message
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_executable(
    cmake_final_check
    src/main.cpp
)
target_link_libraries(
    cmake_final_check
    PRIVATE
    message
)