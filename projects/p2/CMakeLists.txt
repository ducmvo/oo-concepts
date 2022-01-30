cmake_minimum_required(VERSION 3.20)
project(p2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(p2
        duelingJP.cpp
        duelingJP.h
        jumpPrime.cpp
        jumpPrime.h
        p2.cpp)
