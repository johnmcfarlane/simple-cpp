find_package(Catch2 REQUIRED)

add_library(simple)
target_sources(simple
  PUBLIC
    FILE_SET CXX_MODULES FILES
      simple.cpp
)

add_executable(simple.unit-test simple.unit-test.cpp)
target_link_libraries(simple.unit-test Catch2::Catch2WithMain simple)
add_test(simple.unit-test simple.unit-test)

add_executable(reflection-demo reflection-demo.cpp)
add_test(reflection-demo reflection-demo)
