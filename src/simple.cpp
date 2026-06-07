module;

#include <fmt/printf.h>

export module simple;

namespace simple
{
    using fmt::print;


    export constexpr auto add(auto lhs, auto rhs)
    {
        print("{} + {} = {}", lhs, rhs, lhs + rhs);
        if ((lhs^rhs)&1)
        {
            return lhs + rhs;
        }
        else
        {
            return rhs + lhs;
        }
    }
}
