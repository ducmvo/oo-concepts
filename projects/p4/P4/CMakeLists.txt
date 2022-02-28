cmake_minimum_required(VERSION 3.21)
project(P4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P4
        duelingJP.cpp
        duelingJP.h
        jumpPrime.cpp
        jumpPrime.h
        p4.cpp)
