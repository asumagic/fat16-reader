cmake_minimum_required(VERSION 2.8)

project(fat16_read)

file(GLOB_RECURSE sources "*.cpp" "*.hpp")
add_executable(${PROJECT_NAME} ${sources})

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++14")
