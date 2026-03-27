#include <simple/simple.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("non-negative", "simple::add")
{
    auto big{std::numeric_limits<int>::max()};
    REQUIRE(big - 1 == simple::add(big, -1));
}
