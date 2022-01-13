cmake_minimum_required(VERSION 3.16)

project(algorithms-1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # lots of warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


include(FetchContent)
FetchContent_Declare(gtest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG main)
FetchContent_GetProperties(gtest)
if(NOT gtest_POPULATED)
  FetchContent_Populate(gtest)
  add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BUILD_DIR})
endif()

# add_executable(algorithms-1 main.cpp)

# add test target
add_executable(algorithms-1-ut test.cpp)
target_link_libraries(algorithms-1-ut gtest_main gmock_main)