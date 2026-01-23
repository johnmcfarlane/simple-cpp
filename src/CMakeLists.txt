find_package(Catch2 REQUIRED)

add_library(simple INTERFACE)
target_include_directories(simple INTERFACE ".")

add_executable(simple.unit-test simple.unit-test.cpp)
target_link_libraries(simple.unit-test Catch2::Catch2WithMain simple)
add_test(simple.unit-test simple.unit-test)
