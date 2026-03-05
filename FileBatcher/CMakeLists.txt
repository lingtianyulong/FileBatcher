cmake_minimum_required(VERSION 3.19)
project(FileBatcher LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.3/msvc2022_64")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include(FetchContent)
FetchContent_Declare(GSL
    GIT_REPOSITORY "https://github.com/microsoft/GSL"
    GIT_TAG "v4.2.1"
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(GSL)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# 获取 git 版本
find_package(Git QUIET) 
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(GIT_VERSION "unknown")
    message(STATUS "Git not found")
endif()

string(REPLACE "\"" "\\\"" GIT_VERSION_ESCAPED "${GIT_VERSION}")
add_compile_definitions(GIT_VERSION=\"${GIT_VERSION_ESCAPED}\")
set(APP_VERSION_STR "1.0.${GIT_VERSION}")
message(STATUS "Git commit hash: ${GIT_VERSION}")
message(STATUS "App version string: ${APP_VERSION_STR}")

configure_file(
    ${CMAKE_SOURCE_DIR}/version.h.in
    ${CMAKE_BINARY_DIR}/version.h
    @ONLY
)

include_directories(${CMAKE_BINARY_DIR})

if (WIN32)
    set(APP_RC ${CMAKE_SOURCE_DIR}/version.rc)
endif()


qt_standard_project_setup()

add_subdirectory(controls)
add_subdirectory(ui)

if (WIN32)
qt_add_executable(FileBatcher
    WIN32 MACOSX_BUNDLE
    main.cpp
    resources/resource.qrc
    ${UI_SOURCES}
    ${APP_RC}
)
else()
    qt_add_executable(FileBatcher
        main.cpp
        ${UI_SOURCES}
    )
endif()

target_link_libraries(FileBatcher
    PRIVATE
        Qt::Core
        Qt::Widgets
        filebatcher-ui
        advanced-controls
)

include(GNUInstallDirs)

install(TARGETS FileBatcher
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET FileBatcher
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
