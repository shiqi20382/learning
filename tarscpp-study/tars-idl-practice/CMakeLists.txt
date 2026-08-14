# 要求 CMake 版本不能低于 3.16
cmake_minimum_required(VERSION 3.16)

# 定义项目名称，并启用 C++ 语言
project(TarsIdlPractice LANGUAGES CXX)

# 使用 C++14 标准
set(CMAKE_CXX_STANDARD 14)

# 如果编译器不支持 C++14，则停止配置并报错
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 禁用 GNU 特有扩展，使用标准 C++14
set(CMAKE_CXX_EXTENSIONS OFF)

# 保存当前 TarsCpp 源码根目录
set(
    TARSCPP_ROOT
    "${CMAKE_CURRENT_SOURCE_DIR}/../TarsCpp"
)

# 保存已经编译完成的 TarsCpp 构建目录
set(
    TARSCPP_BUILD
    "${TARSCPP_ROOT}/build"
)

# 查找 Linux 线程库
find_package(Threads REQUIRED)

# 查找 zlib 压缩库
find_package(ZLIB REQUIRED)

# 把当前项目需要的头文件目录保存到变量中
set(
    PROJECT_INCLUDE_DIRS
    "${CMAKE_CURRENT_SOURCE_DIR}/generated"
    "${CMAKE_CURRENT_SOURCE_DIR}/service"
    "${TARSCPP_ROOT}/servant"
    "${TARSCPP_ROOT}/util/include"
)

# 把当前项目需要链接的库保存到变量中
set(
    TARS_LINK_LIBRARIES
    "${TARSCPP_BUILD}/lib/libtarsservant.a"
    "${TARSCPP_BUILD}/lib/libtarsutil.a"
    "${TARSCPP_BUILD}/lib/libtarsparse.a"
    ZLIB::ZLIB
    Threads::Threads
    ${CMAKE_DL_LIBS}
)

# 创建本地直接调用测试程序
add_executable(
    hello_local
    main.cpp
    service/HelloImp.cpp
)

# 为本地测试程序添加头文件搜索目录
target_include_directories(
    hello_local
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

# 为本地测试程序链接 TarsCpp 和系统依赖库
target_link_libraries(
    hello_local
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)

# 创建真正的 Tars RPC 服务端程序
add_executable(
    hello_server
    server_main.cpp
    service/HelloImp.cpp
)

# 为 RPC 服务端添加头文件搜索目录
target_include_directories(
    hello_server
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

# 为 RPC 服务端链接 TarsCpp 和系统依赖库
target_link_libraries(
    hello_server
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)
# 创建真正的 Tars RPC 客户端程序
add_executable(
    hello_client
    client_main.cpp
)

# 为客户端添加生成代码和 TarsCpp 头文件目录
target_include_directories(
    hello_client
    PRIVATE
    ${PROJECT_INCLUDE_DIRS}
)

# 为客户端链接 TarsCpp 和系统依赖库
target_link_libraries(
    hello_client
    PRIVATE
    ${TARS_LINK_LIBRARIES}
)

# 控制台中的服务名，必须与部署申请中的服务名完全一致
set(TARS_SERVER_NAME HelloServer)

# 输出目录
set(TARS_PACKAGE_DIR "${CMAKE_BINARY_DIR}/package/${TARS_SERVER_NAME}")

# 让最终二进制文件名与服务名保持一致：bin/HelloServer
set_target_properties(hello_server PROPERTIES OUTPUT_NAME "${TARS_SERVER_NAME}")

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/package")

add_custom_target(${TARS_SERVER_NAME}-tar
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${TARS_PACKAGE_DIR}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${TARS_PACKAGE_DIR}/bin"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${TARS_PACKAGE_DIR}/conf"
    COMMAND ${CMAKE_COMMAND} -E copy
            "$<TARGET_FILE:hello_server>"
            "${TARS_PACKAGE_DIR}/bin/${TARS_SERVER_NAME}"
    COMMAND ${CMAKE_COMMAND} -E tar "cfz"
            "${CMAKE_BINARY_DIR}/${TARS_SERVER_NAME}.tgz"
            --format=gnutar
            "${TARS_SERVER_NAME}"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/package"
    DEPENDS hello_server
    COMMENT "Create Tars deployment package: ${TARS_SERVER_NAME}.tgz"
)