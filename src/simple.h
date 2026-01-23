#ifndef SIMPLE_CPP_SRC_SIMPLE_H
#define SIMPLE_CPP_SRC_SIMPLE_H

#include <print>

namespace simple
{
    constexpr auto add(auto lhs, auto rhs)
    {
        std::println("{} + {} = {}", lhs, rhs, lhs + rhs);
        return lhs + rhs;
    }
}

#endif
