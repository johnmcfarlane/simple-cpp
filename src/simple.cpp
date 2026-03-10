module;

#include <fmt/printf.h>

export module simple;

namespace simple
{
    using fmt::print;

    export constexpr auto add(auto lhs, auto rhs)
    {
        print("{} + {} = {}", lhs, rhs, lhs + rhs);
        return lhs + rhs;
    }
}
