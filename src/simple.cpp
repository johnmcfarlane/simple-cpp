#include <simple/simple.h>

#include <fmt/printf.h>

using fmt::print;

auto simple::add(int lhs, int rhs) -> int
{
    print("{} + {} = {}\n", lhs, rhs, lhs + rhs);
    return lhs + rhs;
}
