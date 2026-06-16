cmake_minimum_required(VERSION 3.21)
project(qt_conan2_example LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
if(TARGET Qt6::WebEngineWidgets)
    message(STATUS "Qt6::WebEngineWidgets available")
    find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)
endif()

add_executable(example main.cpp)
target_link_libraries(example PRIVATE Qt6::Widgets)
if(TARGET Qt6::WebEngineWidgets)
    target_link_libraries(example PRIVATE Qt6::WebEngineWidgets)
endif()
