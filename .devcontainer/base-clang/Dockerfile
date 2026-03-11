FROM mcr.microsoft.com/devcontainers/base:trixie

COPY .devcontainer/base-clang/http_apt_llvm_org_trixie.sources /etc/apt/sources.list.d/http_apt_llvm_org_trixie.sources
RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc

RUN apt-get update \
  && apt-get purge --yes binutils gcc g++ --autoremove \
  && apt-get install --no-install-recommends --quiet --yes \
      clang-22 \
      clang-format-22 \
      clang-tidy-22 \
      gdb \
      libc++-22-dev \
      libclang-rt-22-dev \
      lld-22 \
      ninja-build \
      python3-pip \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-22 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-22 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/bin/lld-22 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
