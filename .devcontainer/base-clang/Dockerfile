FROM mcr.microsoft.com/devcontainers/base:trixie

ARG image_version=main

RUN apt-get update \
  && apt-get upgrade --quiet --yes \
  && apt-get install --no-install-recommends --quiet --yes \
      binutils \
      clang \
      cmake \
      libatomic1 \
      lld \
      ninja-build \
      python3-pip \
  && apt-get purge --quiet --yes \
      g++ \
      gcc \
  && git clone --depth 10 https://github.com/llvm/llvm-project.git \
  && cd llvm-project \
  && git config --add remote.origin.fetch '^refs/heads/users/*' \
  && git config --add remote.origin.fetch '^refs/heads/revert-*' \
  && git checkout ${image_version} \
  && mkdir /build && cd /build \
  && CXX=/usr/bin/clang++ CC=/usr/bin/clang cmake \
      -DLLVM_ENABLE_LIBCXX:BOOL=ON \
      -DLLVM_ENABLE_PROJECTS:STRING="clang;clang-tools-extra;lld;lldb" \
      -DLLVM_ENABLE_RUNTIMES:STRING="libcxx;libcxxabi;libunwind;compiler-rt" \
      -DLLVM_TARGETS_TO_BUILD:STRING="host" \
      -DLLVM_USE_LINKER:STRING=lld \
      -G Ninja \
      /llvm-project/llvm \
  && cmake --build /build --target install \
  && apt-get purge --quiet --yes \
      clang \
      lld \
  && apt-get --quiet --yes autoremove \
  && rm -rf /llvm-project /build /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/local/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/local/bin/clang 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/local/bin/lld 1 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
