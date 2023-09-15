cmake_minimum_required(VERSION 3.25)
project(lab2_oop)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(lab2 simple_class.h)

link_libraries(lab2)

add_executable(lab2_oop main.cpp)
