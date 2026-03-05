cmake_minimum_required(VERSION 3.19)
set(LIB_NAME filebatcher-ui)

project(${LIB_NAME} LANGUAGES CXX)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.3/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE UI_SOURCES "*.ui" "*.h" "*.cpp")  
add_library(${LIB_NAME} STATIC ${UI_SOURCES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/ui)

target_link_libraries(${LIB_NAME} PRIVATE Qt::Core Qt::Widgets)
