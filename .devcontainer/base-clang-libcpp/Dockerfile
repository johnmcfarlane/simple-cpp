FROM mcr.microsoft.com/devcontainers/base:trixie

# TODO: remove once https://github.com/llvm/llvm-project/issues/153385 is resolved
RUN sed -i 's/\(sha1\.second_preimage_resistance =\).*/\1 9999-01-01/' /usr/share/apt/default-sequoia.config

RUN wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh \
  && ./llvm.sh 22 \
  && rm llvm.sh \
  && apt-get install --no-install-recommends --quiet --yes clang-format-22 clang-tidy-22 gdb libc++-22-dev libc++abi-22-dev ninja-build python3-pip \
  && apt-get purge --yes gcc g++ \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-22 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-22 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
