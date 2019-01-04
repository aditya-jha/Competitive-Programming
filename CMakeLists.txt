cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(algorithms)

add_executable(
        output
        uva/11988\ -\ Broken\ Keyboard.cpp
)
