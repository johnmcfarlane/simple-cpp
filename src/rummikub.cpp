module;

#include <cassert>

#include <fmt/printf.h>

#include <array>
#include <bitset>
#include <flat_map>
#include <optional>
#include <utility>
#include <vector>

export module rummikub;

namespace rummikub
{
    using fmt::print;

    using color_index = int;
    using number = int;

    constexpr auto num_colors{color_index{4}};
    constexpr auto num_numbers{number{13}};

    using tile_count = int;

    enum class color
    {
        black,
        red,
        blue,
        orange
    };

    export struct tile
    {
        rummikub::number number;
        color_index color;

        friend constexpr auto operator<=>(tile lhs, tile rhs) -> std::strong_ordering = default;
    };

    constexpr auto valid(tile object)
    {
        return object.color >= 0 && object.number >= 0 && object.color < num_colors && object.number < num_numbers;
    }

    ////////////////////////////////////////////////////////////////////////////////
    // map

    export using map = std::array<std::array<tile_count, num_numbers>, num_colors>;

    auto& count(map& counts, tile key)
    // pre(valid(key))
    {
        assert(valid(key));
        return counts[key.color][key.number];
    }

    auto count(map const& counts, tile key)
    // pre(valid(key))
    {
        assert(valid(key));
        return counts[key.color][key.number];
    }

    ////////////////////////////////////////////////////////////////////////////////
    // sparse_map

    export using sparse_map = std::flat_map<tile, tile_count>;

    auto& count(sparse_map& counts, tile key)
    // pre(valid(key))
    {
        assert(valid(key));
        return counts[key];
    }

    export template <typename ToMap, typename FromMap>
    auto convert(FromMap from)
        requires(std::same_as<FromMap, map> != std::same_as<ToMap, map>) &&
                (std::same_as<FromMap, sparse_map> != std::same_as<ToMap, sparse_map>)
    {
        FromMap converted;
        for (auto const& [tile, tile_count] : from)
        {
            count(converted, tile) = tile_count;
        }
        return converted;
    }

    ////////////////////////////////////////////////////////////////////////////////
    // table

    // half-open interval
    export using run = std::array<number, 2>;
    export using group = std::bitset<num_colors>;

    export using runs = std::vector<run>;
    export using groups = std::vector<group>;

    export struct table
    {
        rummikub::runs runs;
        rummikub::groups groups;

        friend constexpr auto operator==(table const& lhs, table const& rhs) -> bool = default;
    };

    // ////////////////////////////////////////////////////////////////////////////////
    // // problem

    // struct problem
    // {
    //     sparse_map table;
    //     sparse_map rack;
    // };

    // using solution = problem;

    template <typename Converted, typename From> Converted convert(From const& from);

    // // 1 2 3 4 5 6 7 8 9
    // // 0 2 0 0 0 0 0 0 0 - black
    // // 0 1 1 1 0 1 1 1 0 - red
    // // 0 0 0 0 0 0 0 0 0 - blue
    // // 0 1 0 0 0 0 0 0 0 - orange
    export auto try_convert(table& to, map& from) -> bool;

    // Try to make groups starting with to_play and scanning down.
    auto try_convert_group(table& to, map& from, tile to_play, rummikub::group group)
    {
        to.groups.push_back(group);
        for (auto group_pos{to_play}; group_pos.color < num_colors; ++group_pos.color)
        {
            if (group.test(group_pos.color))
            {
                assert(count(from, group_pos) > 0);
                count(from, group_pos)--;
            }
        }

        if (try_convert(to, from))
        {
            return true;
        }

        for (auto group_pos{to_play}; group_pos.color < num_colors; ++group_pos.color)
        {
            if (group[group_pos.color])
            {
                count(from, group_pos)++;
            }
        }
        to.groups.pop_back();

        return false;
    }

    // Try to make groups starting with to_play and scanning down.
    auto try_convert_group(table& to, map& from, tile to_play)
    {
        // Create a color map of which colors are left in the tile map in downwards direction.
        // E.g. if tile is {red, 3}, then
        auto group_candidates{rummikub::group{0}};
        for (auto group_pos{to_play}; group_pos.color < num_colors; ++group_pos.color)
        {
            group_candidates.set(to_play.color, count(from, group_pos) > 0);
        }

        switch (group_candidates.count())
        {
        case 0:
        case 1:
        case 2:
            return false;
        case 3:
            return try_convert_group(to, from, to_play, group_candidates);
        case 4:
            if (try_convert_group(to, from, to_play, group_candidates))
            {
                return true;
            }

            assert(to_play.color == 0);
            for (auto c{color_index{0}}; c < num_colors; c++)
            {
                group_candidates.reset(c);
                if (try_convert_group(to, from, to_play, group_candidates))
                {
                    return true;
                }
                group_candidates.set(c);
            }

            return false;
        default:
            std::unreachable();
        }
    }

    auto try_convert(table& to, map& from, tile to_play)
    {
        auto& tile_count{count(from, to_play)};
        if (tile_count == 0)
        {
            return false;
        }

        if (to_play.color < 2)
        {
            return try_convert_group(to, from, to_play);
        }

        return false;
    }

    export auto try_convert(table& to, map from) -> bool
    {
        for (auto c{color_index{0}}; c < num_colors; c++)
        {
            for (auto n{number{0}}; n < num_numbers; n++)
            {
                if (try_convert(to, from, tile{n, c}))
                {
                    return true;
                }
            }
        }

        return false;
    }

    // template <> auto convert<std::optional<table>>(map from)
    // {
    //     table to;
    //     return try_convert(to, from) ? std::make_optional(to) : std::optional<table>{};
    // }

    // auto valid_table(map table_map)
    // {
    //     return convert<std::optional<table>>(table_map).has_value();
    // }

    // auto valid(problem const& problem)
    // {
    //     return valid_table(problem.table);
    // }

    // pre(valid(problem))
    // {
    //     assert(
    // }
}
