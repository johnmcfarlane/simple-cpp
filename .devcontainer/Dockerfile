FROM gcc:16.1.0

RUN apt-get purge --autoremove --yes gcc libgmp-dev make \
  && apt-get update --quiet \
  && apt-get install --no-install-recommends --quiet --yes \
      ca-certificates \
      gdb \
      git \
      gpg \
      lsb-release \
      ninja-build \
      python3-pip \
      sudo \
      wget \
  && wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh \
  && ./llvm.sh 22 \
  && rm llvm.sh \
  && apt-get install --no-install-recommends --quiet --yes \
      clang-22 \
      clang-format-22 \
      clang-tidy-22 \
      libc++-22-dev \
      libclang-rt-22-dev \
      lld-22 \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-22 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-22 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/bin/lld-22 1

RUN pip install "conan==2.24.0" "shellcheck-py==0.11.0.1" --break-system-packages --no-cache-dir

ENV BUILD_DIR=/root/build

# configure Conan
COPY .devcontainer/conan-config /root/conan-config
RUN conan config install /root/conan-config
RUN rm -rf /root/conan-config
RUN conan profile detect --force
