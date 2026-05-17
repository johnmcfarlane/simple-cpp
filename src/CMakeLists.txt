find_package(Catch2 REQUIRED)
find_package(fmt REQUIRED)

add_library(rummikub)
target_sources(rummikub
  PUBLIC
    FILE_SET CXX_MODULES FILES
      rummikub.cpp
)
target_link_libraries(rummikub PRIVATE fmt::fmt)

add_executable(rummikub.unit-test rummikub.unit-test.cpp)
target_link_libraries(rummikub.unit-test Catch2::Catch2WithMain rummikub)
add_test(rummikub.unit-test rummikub.unit-test)

if (ENABLE_FUZZER)
  add_executable(rummikub.fuzz-test rummikub.fuzz-test.cpp)
  target_compile_options(rummikub.fuzz-test PRIVATE "-fsanitize=fuzzer")
  target_link_libraries(rummikub.fuzz-test rummikub $ENV{FUZZER_CXX_FLAGS})
  add_test(rummikub.fuzz-test rummikub.fuzz-test -max_total_time=5)
endif ()
