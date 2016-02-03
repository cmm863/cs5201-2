cmake_minimum_required(VERSION 3.3)
project(2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/connor/sp2016/cs5201/Homework/2/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp term.hpp term.h polynomial_fnct.h polynomial_fnct.hpp)
add_executable(2 ${SOURCE_FILES})