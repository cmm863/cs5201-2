cmake_minimum_required(VERSION 3.3)
project(2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp term.hpp term.h polynomial_fnct.h polynomial_fnct.hpp)
add_executable(2 ${SOURCE_FILES})