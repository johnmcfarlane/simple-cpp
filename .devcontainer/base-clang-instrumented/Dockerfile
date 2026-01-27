FROM mcr.microsoft.com/devcontainers/base:trixie

RUN apt-get update --quiet \
  && apt-get install --no-install-recommends --quiet --yes binutils clang cmake libz3-4 ninja-build python3-pip \
  && git clone --branch=main --depth=1 https://github.com/llvm/llvm-project.git \
  && mkdir build \
  && cd build \
  && CXX=/usr/bin/clang++ CC=/usr/bin/clang cmake \
    -GNinja \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" \
    -DLLVM_ENABLE_RUNTIMES="compiler-rt;libcxx;libcxxabi;libunwind" \
    ../llvm-project/llvm \
  && ninja install \
  && cd .. \
  && apt-get purge --yes --autoremove clang gcc \
  && apt-get install --no-install-recommends --yes build-essential \
  && apt-get --quiet --yes autoremove \
  && rm -rf llvm-project build /var/lib/apt/lists/*
RUN apt-get update --quiet \
  && apt-get install --no-install-recommends --quiet --yes build-essential gdb \
  && apt-get purge --yes clang gcc g++

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/local/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/local/bin/clang 1 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1
ENV CC=/usr/bin/clang
ENV CXX=/usr/bin/clang++
ENV LD_LIBRARY_PATH=/usr/local/lib/x86_64-unknown-linux-gnu

RUN pip install "cmake~=4.2.1" "conan~=2.24.0" --break-system-packages --no-cache-dir

COPY .devcontainer/images/clang/conan-config /tmp/conan-config
COPY .clang-tidy /
