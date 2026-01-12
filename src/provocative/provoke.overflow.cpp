#include <limits>

auto main() -> int
{
    auto number{std::numeric_limits<int>::max()};
    return number + 1;
}
