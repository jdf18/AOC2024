cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)

project(AOC2024)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Day1 src/day-1/main.cpp)