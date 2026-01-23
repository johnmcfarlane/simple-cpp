#include <catch2/catch_test_macros.hpp>
#include <fuzztest/fuzztest.h>

import simple;

void test_add(int a, int b) {
  REQUIRE(a + b == simple::add(a, b));
}
FUZZ_TEST(simple_fuzz_tests, test_add);
