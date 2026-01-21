FROM mcr.microsoft.com/devcontainers/base:trixie

ARG image_version=main

COPY .devcontainer/base-clang/http_apt_llvm_org_trixie.sources /etc/apt/sources.list.d/http_apt_llvm_org_trixie.sources
RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc

RUN apt-get update
RUN apt-get upgrade --quiet --yes
RUN apt-get install --no-install-recommends --quiet --yes \
      clang-22 \
      clang-format-22 \
      clang-tidy-22 \
      cmake \
      gdb \
      libc++-22-dev \
      libc++abi-22-dev \
      libclang-rt-22-dev \
      libpolly-22-dev \
      lld-22 \
      ninja-build \
      python3-pip

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/bin/lld-22 1 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1

# RUN git clone --branch main --single-branch https://github.com/llvm/llvm-project.git 
# RUN cd llvm-project \
#   && git config --add remote.origin.fetch '^refs/heads/users/*' \
#   && git config --add remote.origin.fetch '^refs/heads/revert-*' \
#   && git checkout ${image_version}
# RUN mkdir /build && cd /build \
#   && CXX=/usr/bin/clang++ CC=/usr/bin/clang cmake \
#       -DCLANG_ENABLE_BOOTSTRAP:BOOL=ON \
#       -DCMAKE_INSTALL_PREFIX:STRING=/install \
      
#       -DLLVM_ENABLE_LIBCXX:BOOL=ON \
#       -DLLVM_ENABLE_PROJECTS:STRING="clang;lld" \
#       -DLLVM_ENABLE_RUNTIMES:STRING="libcxx;libcxxabi" \
#       -DLLVM_TARGETS_TO_BUILD:STRING="X86" \
#       -DLLVM_USE_LINKER:STRING=lld \
#       -G Ninja \
#       /llvm-project/llvm 
# RUN cmake --build /build --target install 
# RUN apt-get purge --autoremove --quiet --yes \
#       clang-22 \
#       clang-format-22 \
#       clang-tidy-22 \
#       libc++-22-dev \
#       libc++abi-22-dev \
#       libclang-rt-22-dev \
#       libpolly-22-dev \
#       lld-22 \
#   && apt-get --quiet --yes autoremove \
#   && rm -rf /llvm-project /build /var/lib/apt/lists/*

RUN git clone --branch main --depth 1 --single-branch https://github.com/llvm/llvm-project.git 
RUN cd llvm-project \
  && git config --add remote.origin.fetch '^refs/heads/users/*' \
  && git config --add remote.origin.fetch '^refs/heads/revert-*' \
  && git checkout ${image_version}
RUN mkdir /build && cd /build \
  && cmake \
      -DCMAKE_C_COMPILER:STRING=/usr/bin/clang \
      -DCMAKE_CXX_COMPILER:STRING=/usr/bin/clang++ \
      -DCMAKE_INSTALL_PREFIX:STRING=/install \
      -DLLVM_ENABLE_LIBCXX:BOOL=ON \
      -DLLVM_ENABLE_PROJECTS:STRING="clang;lld" \
      -DLLVM_ENABLE_RUNTIMES:STRING="libcxx;libcxxabi;libunwind" \
      -DLLVM_INSTALL_TOOLCHAIN_ONLY:BOOL=ON \
      -DLLVM_TARGETS_TO_BUILD:STRING="X86" \
      -DLLVM_USE_LINKER:STRING=lld-22 \
      -G Ninja \
      /llvm-project/llvm 
RUN cmake --build /build --target install
RUN cmake --build /build --target install install-cxx install-cxxabi

RUN cmake \
      -DCLANG_ENABLE_BOOTSTRAP:BOOL=ON \
      -DCMAKE_C_COMPILER:STRING=/install/bin/clang \
      -DCMAKE_CXX_COMPILER:STRING=/install/bin/clang++ \
      -DLLVM_DISTRIBUTION_COMPONENTS:STRING="clang;lld" \
      -DLLVM_ENABLE_LIBCXX:BOOL=ON \
      -DLLVM_ENABLE_PROJECTS:STRING="clang;lld" \
      -DLLVM_ENABLE_RUNTIMES:STRING="libcxx;libcxxabi;libunwind" \
      -DLLVM_INSTALL_TOOLCHAIN_ONLY:BOOL=ON \
      -DLLVM_TARGETS_TO_BUILD:STRING="X86" \
      -DLLVM_USE_LINKER:STRING=lld-22 \
      -G Ninja \
      /llvm-project/llvm
RUN cmake --build /build --target install-distribution
#   && apt-get --quiet --yes autoremove \
#   && rm -rf /llvm-project /build /var/lib/apt/lists/*

RUN apt-get purge --autoremove --quiet --yes \
      clang-22 \
      clang-format-22 \
      clang-tidy-22 \
      libc++-22-dev \
      libc++abi-22-dev \
      libclang-rt-22-dev \
      libpolly-22-dev \
      lld-22 

RUN update-alternatives --install /usr/bin/clang++ clang++ /install/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/clang clang /install/bin/clang 1 \
  && update-alternatives --install /usr/bin/ld ld /install/bin/lld 1 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 1 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
