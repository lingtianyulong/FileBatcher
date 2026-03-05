cmake_minimum_required(VERSION 3.19)
set(LIB_NAME filebatcher-controls)

project(${LIB_NAME} LANGUAGES CXX)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE CONTROLS_SOURCES
        CONFIGURE_DEPENDS
        "buttons/*.h"
        "buttons/*.cpp")

add_library(${LIB_NAME} STATIC ${CONTROLS_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/controls)

target_link_libraries(${LIB_NAME} PUBLIC Qt::Core Qt::Widgets Microsoft.GSL::GSL)
