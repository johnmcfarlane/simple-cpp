#include <print>
#include <thread>

auto main() noexcept(false) -> int
{
    auto shared_state{0};
    std::jthread const thread{[&] { shared_state = 1; }};
    std::print("{}\n", shared_state);
}
