cmake_minimum_required(VERSION 3.16)
project(TarsCalculatorPractice LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(
    TARSCPP_ROOT
    "${CMAKE_CURRENT_SOURCE_DIR}/../TarsCpp"
)
set(
    TARSCPP_BUILD
    "${TARSCPP_ROOT}/build-study"
)
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)
set(
    PROJECT_INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/generated"
    "${CMAKE_CURRENT_SOURCE_DIR}/service"
    "${TARSCPP_ROOT}/servant"
    "${TARSCPP_ROOT}/util/include"
)
set(
    TARS_LINK_LIBRARIES
    "${TARSCPP_BUILD}/lib/libtarsservant.a"
    "${TARSCPP_BUILD}/lib/libtarsutil.a"
    "${TARSCPP_BUILD}/lib/libtarsparse.a"
    ZLIB::ZLIB
    Threads::Threads
    ${CMAKE_DL_LIBS}
)
add_executable(
    calculator_server
    server_main.cpp
    service/CalculatorImp.cpp
)

target_include_directories(
    calculator_server
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

target_link_libraries(
    calculator_server
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)

add_executable(
    calculator_client
    client_main.cpp
)

target_include_directories(
    calculator_client
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

target_link_libraries(
    calculator_client
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)