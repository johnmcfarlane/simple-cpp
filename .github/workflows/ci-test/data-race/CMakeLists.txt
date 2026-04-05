cmake_minimum_required(VERSION 4.3)
project(data-race)

include(CTest)

find_package(fmt REQUIRED)
add_executable(data-race data-race.cpp)
target_link_libraries(data-race fmt::fmt)
add_test(data-race data-race)
