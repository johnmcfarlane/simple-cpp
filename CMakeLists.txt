cmake_minimum_required(VERSION 4.2.1)
project(simple-cpp LANGUAGES CXX)

# TODO: Correct C++ standard via `CMAKE_CXX_EXTENSIONS OFF` and `compiler.cppstd=gnu26`.
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

add_subdirectory(src)
