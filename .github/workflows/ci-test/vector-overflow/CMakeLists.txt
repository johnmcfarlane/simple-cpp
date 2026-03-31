cmake_minimum_required(VERSION 4.2)
project(vector-overflow)

include(CTest)

add_executable(vector-overflow vector-overflow.cpp)
add_test(vector-overflow vector-overflow)
