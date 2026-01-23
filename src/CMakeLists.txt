find_package(Threads REQUIRED)

add_library(simple)
target_sources(simple
  PUBLIC
    FILE_SET CXX_MODULES FILES
      simple.cpp
)

#add_executable(simple.unit-test simple.unit-test.cpp)
#target_link_libraries(simple.unit-test Catch2::Catch2WithMain simple)
#add_test(simple.unit-test simple.unit-test)

if (FUZZ_TEST)
  add_executable(simple.fuzz-test simple.fuzz-test.cpp)
  target_compile_options(simple.fuzz-test PRIVATE "-fsanitize=fuzzer")
  target_link_libraries(simple.fuzz-test simple Threads::Threads $ENV{FUZZ_TEST_LINKER_FLAGS} "-fsanitize=fuzzer" "c++" "c++abi")
  add_test(simple.fuzz-test simple.fuzz-test)
endif ()
