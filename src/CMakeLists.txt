include(FetchContent)
FetchContent_Declare(
  fuzztest
  GIT_REPOSITORY https://github.com/google/fuzztest.git
  GIT_TAG 2025-08-05
)
FetchContent_MakeAvailable(fuzztest)

find_package(Catch2 REQUIRED)

add_library(simple)
target_sources(simple
  PUBLIC
    FILE_SET CXX_MODULES FILES
      simple.cpp
)

add_executable(simple.unit-test simple.unit-test.cpp)
target_link_libraries(simple.unit-test Catch2::Catch2WithMain fuzztest::fuzztest simple)
add_test(simple.unit-test simple.unit-test)

add_executable(simple.fuzz-test simple.fuzz-test.cpp)
target_link_libraries(simple.fuzz-test Catch2::Catch2WithMain simple)
add_test(simple.fuzz-test simple.fuzz-test)
