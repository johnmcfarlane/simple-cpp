// https://www.youtube.com/watch?v=7z9NNrRDHQU
// https://godbolt.org/z/P6jeKK3of

#include <algorithm>
#include <iostream>
#include <print>
#include <sstream>
#include <string>
#include <string_view>
#include <utilities/meta>

using namespace std;

template<typename Opts> // <== type itself is an input
auto parse_options( vector<string_view> const& args )
    -> Opts 
{
    Opts opts;

    constexpr auto ctx = meta::access_context::current();
    template for (      // <== expansion statement, "stamped out"
        constexpr auto dm :
        define_static_array(nonstatic_data_members_of(^^Opts, ctx))
    ) {                     // ^^ reflection expression + meta::fn
        auto it = ranges::find_if(args, [](string_view arg) {
            return arg.starts_with("--")
                && arg.substr(2) == identifier_of(dm);
        });

        //  If we found this switch name, and it's
        //  followed by a value, read the value
        if (
            it != args.end()
            && it+1 != args.end()
            && !(it+1)->starts_with("--")
            )
        {
            auto iss = stringstream(it[1]);
            if (iss >> opts.[:dm:]; !iss) { // <== [: splice :]
                println( "Error: Value supplied for {} is not a valid {}",
                         *it, display_string_of(type_of(dm)) );
                exit(EXIT_FAILURE);         // e.g., "int" at compile time,
            }                               // better than typeid().name()
        }                                   // (e.g., "i") at run time
    }
    return opts;
}

struct MyOpts {
    string fname = "input.txt";  // "--fname <string>"
    int    count = 1;            // "--count <int>"
    //float  pi    = 3.14159;      // "--pi <float>"
};

auto main(int argc, char *argv[]) -> int
{
    MyOpts opts = parse_options<MyOpts>({ argv, argv+argc});
    println("opts.fname is \"{}\"", opts.fname);
    println("opts.count is {}",     opts.count);
    //println("opts.pi    is {}",     opts.pi);
}
