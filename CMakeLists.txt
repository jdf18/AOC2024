cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)

project(AOC2024)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Day1 src/day-1/main.cpp)
add_executable(Day2 src/day-2/main.cpp)
add_executable(Day3 src/day-3/main.cpp)
add_executable(Day4 src/day-4/main.cpp)
add_executable(Day5 src/day-5/main.cpp)