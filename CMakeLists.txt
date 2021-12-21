cmake_minimum_required(VERSION 3.17)
project(pddb)

set(CMAKE_CXX_STANDARD 14)

add_executable(pddb main.cpp poisson_disc_distribution.hpp FPD_Random.cpp)