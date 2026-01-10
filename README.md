# Simple C++ Project Template

## Introduction

### Requirements

A [Development Containers](https://containers.dev/)-based setup is supported and tested with the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension.

View any [Dockerfile](.devcontainer/images/gcc/Dockerfile) for an example of system requirements, which include

* [Clang](https://clang.llvm.org/) 22 or [GCC](https://gcc.gnu.org/) 16
* [CMake](https://cmake.org/) 4.2.1
* [Conan](https://conan.io/) 2.24.0

and optionally:

* Clang-Tidy
* Ninja
* GDB

See [conanfile.txt](conanfile.txt) for software dependencies, which include:

* [Catch2](https://github.com/catchorg/Catch2) 3.12.0

## Instructions

Basic VS Code tasks are provided to build and test the software. To build and test:

1. Follow the [VS Code Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers#installation) instructions.
1. Run command, "Dev Containers: Open Folder in Container..." and select [the project directory](.).
1. Choose the [GCC test](.devcontainer/gcc-test/devcontainer.json) dev container.
1. Run command, "Dev Containers: Rebuild Container".
1. Run command, "Tasks: Run Test Task".
