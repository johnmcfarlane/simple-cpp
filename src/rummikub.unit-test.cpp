#include <catch2/catch_test_macros.hpp>

#include <limits>

import rummikub;

TEST_CASE("non-negative", "rummikub::add")
{
    constexpr auto expected_run{rummikub::run{2, 6}};
    auto const expected_runs{rummikub::runs{expected_run}};
    auto const expected{rummikub::table{expected_runs, {}}};
    constexpr auto from_tile{rummikub::tile{2, 0}};
    auto const from{rummikub::convert<rummikub::map>(rummikub::sparse_map{{from_tile, 1}})};

    rummikub::table to;
    REQUIRE(rummikub::try_convert(to, from));
    REQUIRE(expected == to);
}
