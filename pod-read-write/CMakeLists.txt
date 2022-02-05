cmake_minimum_required(VERSION 3.15)

project(NokiaTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # lots of warnings
    add_compile_options(-Wall
                        -Wextra
                        )
endif()

add_executable(NokiaTest main.cpp)