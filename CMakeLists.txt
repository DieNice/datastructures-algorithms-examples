cmake_minimum_required(VERSION 3.13)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA
        README.MD main.cpp src/Permutations.cpp src/Permutations.h)
