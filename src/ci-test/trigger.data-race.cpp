import std;

auto main() noexcept(false) -> int
{
    auto shared_state{0};
    std::jthread thread{[&] { shared_state = 1; }};
    std::print("{}\n", shared_state);
}
