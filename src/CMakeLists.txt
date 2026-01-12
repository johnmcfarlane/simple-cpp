find_package(Catch2 REQUIRED)

add_subdirectory(ci-test)

add_library(simple)
target_sources(simple
  PUBLIC
    FILE_SET CXX_MODULES FILES
      simple.cpp
)
target_link_libraries(simple)
target_compile_features(simple INTERFACE cxx_std_26)

add_executable(simple.unit-test simple.unit-test.cpp)
target_link_libraries(simple.unit-test simple)
target_link_libraries(simple.unit-test Catch2::Catch2WithMain simple)
add_test(simple.unit-test simple.unit-test)
