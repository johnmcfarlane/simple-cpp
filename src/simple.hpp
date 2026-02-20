#include <print>

namespace simple
{
    constexpr auto add(auto lhs, auto rhs)
    {
        std::println("{} + {} = {}", lhs, rhs, lhs + rhs);
        return lhs + rhs;
    }
}
