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

# 创建单次异步 Calculator 客户端目标
add_executable(
    calculator_async_client
    async_client_main.cpp
)

# 为异步客户端添加生成代码和 TarsCpp 头文件目录
target_include_directories(
    calculator_async_client
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

# 为异步客户端链接 TarsCpp 和系统依赖库
target_link_libraries(
    calculator_async_client
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)

# 创建错误端口测试客户端
add_executable(
    calculator_async_wrong_port
    async_client_wrong_port.cpp
)

# 为测试客户端添加头文件搜索目录
target_include_directories(
    calculator_async_wrong_port
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

# 为测试客户端链接 TarsCpp 和系统依赖
target_link_libraries(
    calculator_async_wrong_port
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)

set(TARS_SERVER_NAME CalculatorServer)
set(TARS_PACKAGE_DIR "${CMAKE_BINARY_DIR}/package/${TARS_SERVER_NAME}")
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/package")

add_custom_target(${TARS_SERVER_NAME}-tar
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${TARS_PACKAGE_DIR}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${TARS_PACKAGE_DIR}/bin"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${TARS_PACKAGE_DIR}/conf"
    COMMAND ${CMAKE_COMMAND} -E copy
            "$<TARGET_FILE:calculator_server>"
            "${TARS_PACKAGE_DIR}/bin/${TARS_SERVER_NAME}"
    COMMAND ${CMAKE_COMMAND} -E tar "cfz"
            "${CMAKE_BINARY_DIR}/${TARS_SERVER_NAME}.tgz"
            "${TARS_SERVER_NAME}"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/package"
    DEPENDS calculator_server
)