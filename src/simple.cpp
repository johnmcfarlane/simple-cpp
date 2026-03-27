#include <simple/simple.h>

#include <print>

using std::print;

auto simple::add(int lhs, int rhs) -> int
{
    print("{} + {} = {}\n", lhs, rhs, lhs + rhs);
    return lhs + rhs;
}
