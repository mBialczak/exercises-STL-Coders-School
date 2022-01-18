cmake_minimum_required(VERSION 3.15)

project(modifying-algos-task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # lots of warnings
    add_compile_options(-Wall)
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories( ${CMAKE_SOURCE_DIR}/include)

add_executable(mod-algos-task main.cpp)