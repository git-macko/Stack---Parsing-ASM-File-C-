cmake_minimum_required(VERSION 3.21)
project(Stack___Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Stack___Assignment_3
        cpu.cpp
        cpu.h
        CPUDriver.cpp
        Prog1.asm
        Prog2.asm
        test.sh)
