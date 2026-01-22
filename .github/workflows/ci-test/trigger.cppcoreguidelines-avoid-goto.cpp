static auto f() -> void
{
    goto end;
end:
}

auto main() -> int
{
    f();
}
