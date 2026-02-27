// import simple;
// import std;

#include "simple.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const* data, std::size_t size)
{
    struct
    {
        int a;
        int b;
    } params;

    if (size != sizeof(params))
    {
        return -1;
    }

    std::memcpy(&params, data, sizeof(params));
    if (params.a > 2)
    {
        return -1;
    }
    if (params.a < -2)
    {
        return -1;
    }
    if (params.b > 2)
    {
        return -1;
    }
    if (params.b < -2)
    {
        return -1;
    }

    simple::add(params.a, params.b);
    return 0;
}
