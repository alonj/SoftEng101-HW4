cmake_minimum_required(VERSION 3.10)
project(HW4_AttachedFiles)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(HW4_AttachedFiles
        Airplane.h
        main.cpp
        Terminal.h)
