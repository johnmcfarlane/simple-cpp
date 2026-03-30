#include <vector>

auto main() -> int
{
    std::vector<int> numbers;
    numbers.reserve(1);
    (void)numbers[0];
}
