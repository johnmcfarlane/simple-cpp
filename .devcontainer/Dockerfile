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
RUN conan profile detect --force

# configure remote
RUN git clone --branch=simple-cpp --depth=1 https://github.com/johnmcfarlane/conan-center-index.git ~/conan-center-index \
    && cd ~/conan-center-index \
    && git checkout eed65da43
RUN conan remote disable conancenter
RUN conan remote add local ~/conan-center-index

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
