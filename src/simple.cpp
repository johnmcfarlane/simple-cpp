module;

export module simple;

import std;

namespace simple
{
    export constexpr auto add(auto lhs, auto rhs)
    {
        std::println("{} + {} = {}", lhs, rhs, lhs + rhs);
        return lhs + rhs;
    }
}
