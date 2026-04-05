#include <fmt/printf.h>

#include <thread>

auto main() -> int
{
    auto shared_state{0};
    std::jthread const thread{[&] { shared_state = 1; }};
    fmt::print("{}\n", shared_state);
}
