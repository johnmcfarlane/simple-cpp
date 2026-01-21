FROM mcr.microsoft.com/devcontainers/base:trixie

ARG image_version=main

RUN apt-get update \
  && apt-get purge --quiet --yes --autoremove \
      g++ \
      gcc \
  && apt-get upgrade --quiet --yes \
  && apt-get install --no-install-recommends --quiet --yes \
      binutils \
      build-essential \
      clang \
      cmake \
      gdb \
      libc++-dev \
      libc++abi-dev \
      lld \
      ninja-build \
      python3-pip \
  && git clone --branch main --single-branch https://github.com/llvm/llvm-project.git \
  && cd llvm-project && git checkout ${image_version} \
  && mkdir /build && cd /build \
  && CXX=/usr/bin/clang++ CC=/usr/bin/clang cmake \
      -DCMAKE_CXX_FLAGS="-stdlib=libc++ -I/usr/local/include/c++/v1 -L/usr/local/lib" \
      -DLLVM_ENABLE_LIBCXX:BOOL=ON \
      -DLLVM_ENABLE_PROJECTS:STRING="clang;clang-tools-extra;lld" \
      -DLLVM_ENABLE_RUNTIMES:STRING="libcxx;libcxxabi;libunwind;compiler-rt" \
      -DLLVM_TARGETS_TO_BUILD:STRING="host" \
      -DLLVM_USE_LINKER:STRING=lld \
      -G Ninja \
      /llvm-project/llvm \
  && cmake --build /build --target install 
# RUN  apt-get --quiet --yes autoremove \
#   && rm -rf /llvm-project /build /var/lib/apt/lists/*

# RUN apt-get purge --quiet --yes --autoremove \
#       clang \
#       cmake \
#       g++ \
#       gcc \
#       libc++-dev \
#       libc++abi-dev \
#       lld 
RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/local/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/local/bin/clang 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/local/bin/lld 1 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1

# RUN apt-get install --no-install-recommends --quiet --yes libz3-4
# # RUN apt-get install --no-install-recommends --yes build-essential
# # RUN apt-get update --quiet
# # RUN apt-get install --no-install-recommends --quiet --yes gdb
# # RUN apt-get purge --yes clang
# # RUN apt-get --quiet --yes autoremove
# # RUN rm -rf /var/lib/apt/lists/*
# ENV CC=/usr/bin/clang
# ENV CXX=/usr/bin/clang++
# ENV LD_LIBRARY_PATH=/usr/local/lib/x86_64-unknown-linux-gnu
RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
