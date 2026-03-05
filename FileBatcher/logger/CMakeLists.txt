cmake_minimum_required(VERSION 3.19)
set(LIB_NAME filebatcher-logger)

project(${LIB_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(${LIB_NAME} STATIC "logger.cpp" "logger.h")

target_include_directories(${LIB_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/logger
        ${CMAKE_SOURCE_DIR}/thirdparty/spdlog-1.17.0/include
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        Microsoft.GSL::GSL
        filebatcher-thirdparty
        Qt::Core
)