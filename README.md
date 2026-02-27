# Simple C++ Project Template

## Introduction

### Requirements

A [Development Containers](https://containers.dev/)-based setup is supported and tested with the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension.

View any [Dockerfile](.devcontainer/base-gcc/Dockerfile) for an example of system requirements, which include

* [Clang](https://clang.llvm.org/) 21 or [GCC](https://gcc.gnu.org/) 16
* [Conan](https://conan.io/) 2.x

and optionally:

* Clang-Tidy
* Ninja
* GDB

See [conanfile.txt](conanfile.txt) for software dependencies, which include:

* [Catch2](https://github.com/catchorg/Catch2) 3.12.0

## Instructions

Basic VS Code tasks are provided to build and test the software. To build and test:

1. Follow the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers#installation) instructions.
1. Connect to the Internet.
1. Run command, "Dev Containers: Open Folder in Container..." and select [the project directory](.).
1. Choose the [GCC test](.devcontainer/gcc-test/devcontainer.json) dev container.
1. Run command, "Tasks: Run Test Task".


cmake --toolchain /tmp/build/conan_toolchain.cmake -B /tmp/build -DCMAKE_BUILD_TYPE=Release -DFUZZ_TEST=1 -DCMAKE_PREFIX_PATH=/tmp/build -G Ninja -S .


Fuzzer branch command
> /usr/bin/clang++ -m64 -stdlib=libc++ -O3 -DNDEBUG -m64 -Xlinker --dependency-file=src/CMakeFiles/simple.fuzz-test.dir/link.d src/CMakeFiles/simple.fuzz-test.dir/simple.fuzz-test.cpp.o -o src/simple.fuzz-test  -fsanitize=fuzzer && :
produces _many_ linker errors
