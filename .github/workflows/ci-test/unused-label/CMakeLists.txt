cmake_minimum_required(VERSION 4.2.1)
project(unused-label)

include(CTest)

add_executable(unused-label unused-label.cpp)
add_test(unused-label unused-label)
