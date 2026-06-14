# Simple C++ Project Template

## Introduction

### Requirements

A [Development Containers](https://containers.dev/)-based setup is supported and tested with the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension.

View [Dockerfile](.devcontainer/Dockerfile) for an example of system requirements, which include

* [Clang](https://clang.llvm.org/) 22 or [GCC](https://gcc.gnu.org/) 16
* [Conan](https://conan.io/) 2.x

and optionally:

* Clang-Tidy
* Ninja
* GDB

See [conanfile.txt](conanfile.txt) for software dependencies, which include:

* [Catch2](https://github.com/catchorg/Catch2) 3.14
* [fmt](https://github.com/fmtlib/fmt) 12

## Instructions

Basic VS Code tasks are provided to build and test the software. To build and test:

1. Follow the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers#installation) instructions.
1. Open the project in a container:
   1. Run command, "Dev Containers: Open Folder in Container...".
   1. Select [the project directory](.).
1. Run the _test_ task:
   1. Run command, "Tasks: Run Task", select "test".
   1. Choose profile, [gcc-release](scripts/profiles/gcc-release).
