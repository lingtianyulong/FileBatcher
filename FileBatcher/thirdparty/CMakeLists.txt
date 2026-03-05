cmake_minimum_required(VERSION 3.19)
set(LIB_NAME filebatcher-thirdparty)

project(${LIB_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(${LIB_NAME} INTERFACE)

target_include_directories(${LIB_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/spdlog-1.17.0/include
)
