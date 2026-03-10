cmake_minimum_required(VERSION 4.3)
project(data-race)

include(CTest)

add_executable(data-race data-race.cpp)
add_test(data-race data-race)
