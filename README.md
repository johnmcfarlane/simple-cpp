# ???

```sh
clang++ .github/workflows/ci-test/trigger.integer-overflow.cpp --stdlib=libc++ -lc++
```

> clang++: error: unable to execute command: posix_spawn failed: No such file or directory

```sh
sudo apt-get purge --quiet --yes clang          g++       gcc       libc++-dev       libc++abi-dev
sudo apt-get install       clang
```

Don't autoremove clang or g++ or 
Can auto-remove purge  libc++-dev       libc++abi-dev gcc g++


Clang 23:
* /usr/local/bin/clang++

Clang 19:
* /usr/bin/clang++-19

/usr/local/lib/x86_64-unknown-linux-gnu/libc++.modules.json

-I/usr/local/lib/x86_64-unknown-linux-gnu/../../share/libc++/v1
-> /usr/local/share/libc++/v1

/usr/local/include/c++/v1/flat_map

"/usr/local/bin/clang-scan-deps" -format=p1689 -- /usr/bin/clang++  -I/usr/local/lib/x86_64-unknown-linux-gnu/../../share/libc++/v1 -m64 -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_FAST -fsanitize-trap -fsanitize=address,undefined -g -Wall -Werror -Wextra -O3 -DNDEBUG -std=gnu++26 -Wno-reserved-module-identifier -x c++ /usr/local/share/libc++/v1/std.cppm -c -o CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o -resource-dir "/usr/local/lib/clang/23" -MT CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi -MD -MF CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.d > CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.tmp && mv CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.tmp CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi

# ==============================

/usr/local/share/libc++/v1/std.cppm:63:10: fatal error: 'flat_map' file not found

From .devcontainer, /usr/local/lib/x86_64-unknown-linux-gnu/libc++.modules.json
specifies include directory, ../../share/libc++/v1
i.e. /usr/local/lib/x86_64-unknown-linux-gnu/../../share/libc++/v1
i.e. /usr/local/share/libc++/v1

but flat_map is in /usr/local/include/c++/v1/flat_map


"/usr/local/bin/clang-scan-deps" -format=p1689 -- /usr/bin/clang++  -I/usr/local/lib/x86_64-unknown-linux-gnu/../../share/libc++/v1 -m64 -stdlib=libc++ -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_DEBUG -fno-sanitize-recover=all -fsanitize=address,undefined -g -Wall -Werror -Wextra -O3 -DNDEBUG -std=gnu++26 -Wno-reserved-module-identifier -x c++ /usr/local/share/libc++/v1/std.cppm -c -o CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o -resource-dir "/usr/local/lib/clang/23" -MT CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi -MD -MF CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.d > CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.tmp && mv CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi.tmp CMakeFiles/__cmake_cxx26.dir/usr/local/share/libc++/v1/std.cppm.o.ddi


--rtlib=compiler-rt
