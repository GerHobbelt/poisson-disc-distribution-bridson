cmake_minimum_required(VERSION 3.17)
project(poisson-disc-distribution-bridson)

set(CMAKE_CXX_STANDARD 14)

add_executable(poisson-disc-distribution-bridson poisson_disc_distribution.hpp FPD_Random.cpp)