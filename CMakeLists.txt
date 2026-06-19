cmake_minimum_required(VERSION 3.21)
project(qt_conan2_example LANGUAGES CXX)

# Place built binaries (executables, libraries, archives) in the top-level
# binary directory so they don't end up in generator-specific subfolders.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(source)