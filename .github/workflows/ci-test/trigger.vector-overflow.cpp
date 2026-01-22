#include <vector>

auto main() noexcept(false) -> int
{
    std::vector<int> numbers;
    numbers.reserve(1);
    (void)numbers[0];
}
