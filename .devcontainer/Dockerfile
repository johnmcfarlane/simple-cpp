FROM gcc:16.1.0

ENV llvm_version=22
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
  && ./llvm.sh $llvm_version \
  && rm llvm.sh \
  && apt-get install --no-install-recommends --quiet --yes \
      clang-$llvm_version \
      clang-format-$llvm_version \
      clang-tidy-$llvm_version \
      libc++-$llvm_version-dev \
      libclang-rt-$llvm_version-dev \
      lld-$llvm_version \
  && apt-get --quiet --yes autoremove \
  && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-$llvm_version 1 \
  && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-$llvm_version 1 \
  && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-$llvm_version 1 \
  && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-$llvm_version 1 \
  && update-alternatives --install /usr/bin/ld ld /usr/bin/lld-$llvm_version 1

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir

RUN groupadd --gid 1000 tux \
    && useradd --create-home --gid 1000 --shell /bin/bash --uid 1000 tux \
    && echo tux ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/tux \
    && chmod 0440 /etc/sudoers.d/tux
USER tux

ENV BUILD_DIR=/home/tux/build

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
COPY --chown=tux .devcontainer/conan-config /home/tux/conan-config
RUN conan config install /home/tux/conan-config
RUN rm -rf /home/tux/conan-config
ARG cxx
ENV CXX=$cxx
RUN conan profile detect --force

# install dependencies
COPY --chown=tux conanfile.txt /home/tux
ARG profile
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=${profile} \
    /home/tux
RUN rm /home/tux/conanfile.txt

# append dev environment script to user environment script
RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
