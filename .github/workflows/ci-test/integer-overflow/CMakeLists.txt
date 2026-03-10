cmake_minimum_required(VERSION 4.3)
project(integer-overflow)

include(CTest)

add_executable(integer-overflow integer-overflow.cpp)
add_test(integer-overflow integer-overflow)
