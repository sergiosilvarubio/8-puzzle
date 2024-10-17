cmake_minimum_required(VERSION 3.29)
project(8_puzzle)

set(CMAKE_CXX_STANDARD 20)

add_executable(8_puzzle main.cpp grid.hpp grid.cpp search_algorithms.hpp search_algorithms.cpp
        main.cpp)
