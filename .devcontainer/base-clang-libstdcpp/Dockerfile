ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

# TODO: remove once https://github.com/llvm/llvm-project/issues/153385 is resolved
RUN sed -i 's/\(sha1\.second_preimage_resistance =\).*/\1 9999-01-01/' /usr/share/apt/default-sequoia.config

# ca-certificates curl gnulib ???
RUN apt-get update --quiet \
  && apt-get upgrade --yes \
  && apt-get install --no-install-recommends --quiet --yes lsb-release \
  && wget https://apt.llvm.org/llvm.sh \
  && chmod +x llvm.sh \
  && ./llvm.sh 22 \
  && rm llvm.sh \
  && apt-get install --no-install-recommends --quiet --yes clang-format-22 clang-tidy-22 gdb ninja-build python3-pip \
  && apt-get purge --yes gcc g++ \
  && apt-get install --no-install-recommends --quiet --yes libstdc++-14-dev \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-22 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-22 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-22 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-22 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir
