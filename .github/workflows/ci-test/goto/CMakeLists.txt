cmake_minimum_required(VERSION 4.2.1)
project(goto)

include(CTest)

add_executable(goto goto.cpp)
add_test(goto goto)
