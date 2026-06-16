cmake_minimum_required(VERSION 3.21)
project(qt_conan2_example LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE Qt6::Widgets)
