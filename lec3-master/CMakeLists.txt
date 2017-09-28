cmake_minimum_required(VERSION 3.6)
project(Lec3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
    BadStack.cpp
    StackErrors.cpp
)
add_executable(Lec3 ${SOURCE_FILES})