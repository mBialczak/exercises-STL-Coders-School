cmake_minimum_required(VERSION 3.15)

project(map-0x03-task CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # lots of warnings
    add_compile_options(-Wall)
endif()

add_executable(map-task-0x03 main.cpp)