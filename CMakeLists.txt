cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(simple-cpp LANGUAGES CXX)

# TODO: Correct C++ standard via `CMAKE_CXX_EXTENSIONS OFF` and `compiler.cppstd=gnu26`.
set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

add_subdirectory(src)
