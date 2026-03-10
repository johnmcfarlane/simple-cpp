cmake_minimum_required(VERSION 4.3)
project(goto)

include(CTest)

add_executable(goto goto.cpp)
add_test(goto goto)
