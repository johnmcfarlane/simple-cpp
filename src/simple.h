#ifndef SIMPLE_CPP_SRC_SIMPLE_H
#define SIMPLE_CPP_SRC_SIMPLE_H

#include <print>

namespace simple
{
    using std::print;

    constexpr auto add(auto lhs, auto rhs)
    {
        print("{} + {} = {}\n", lhs, rhs, lhs + rhs);
        return lhs + rhs;
    }
}

#endif
