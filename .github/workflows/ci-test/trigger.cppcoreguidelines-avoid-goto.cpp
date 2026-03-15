namespace
{
    auto f() -> void
    {
        goto my_label;
    my_label:
    }
}

auto main() -> int
{
    f();
}
