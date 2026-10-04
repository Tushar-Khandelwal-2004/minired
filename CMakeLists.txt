cmake_minimum_required(VERSION 3.16)

project(minired)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minired
    src/main.cpp
)
add_executable(day02_fd learn/day02_fd_test.cpp)