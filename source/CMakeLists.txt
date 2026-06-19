set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(example main.cpp TreeWidget.cpp)
target_compile_features(example PUBLIC cxx_std_23)
target_link_libraries(example PRIVATE Qt6::Widgets)
