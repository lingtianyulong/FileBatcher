cmake_minimum_required(VERSION 3.19)
set(LIB_NAME filebatcher-helper)

project(${LIB_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE HELPER_SOURCES
        CONFIGURE_DEPENDS
        "*.h"
        "*.cpp")

add_library(${LIB_NAME} STATIC ${HELPER_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/helper)

target_link_libraries(${LIB_NAME} PUBLIC Qt::Core Qt::Widgets Microsoft.GSL::GSL)
