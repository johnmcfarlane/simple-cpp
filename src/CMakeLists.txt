find_package(Catch2 REQUIRED)
find_package(fmt REQUIRED)

add_library(simple)
target_sources(simple
  PUBLIC
    FILE_SET CXX_MODULES FILES
      simple.cpp
)
target_link_libraries(simple PRIVATE fmt::fmt)

add_executable(simple.unit-test simple.unit-test.cpp)
target_link_libraries(simple.unit-test Catch2::Catch2WithMain simple)
add_test(simple.unit-test simple.unit-test)

if (ENABLE_FUZZER)
  add_executable(simple.fuzz-test simple.fuzz-test.cpp)
  target_compile_options(simple.fuzz-test PRIVATE "-fsanitize=fuzzer")
  target_link_libraries(simple.fuzz-test simple $ENV{FUZZER_CXX_FLAGS})
  add_test(simple.fuzz-test simple.fuzz-test -max_total_time=5)
endif ()
