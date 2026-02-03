FROM gcc:trixie

ARG image_version=trunk

RUN apt-get update --quiet \
  && apt-get upgrade --yes \
  && apt-get install --no-install-recommends --quiet --yes binutils build-essential flex gcc-multilib gdb gnulib libgmp-dev libmpc3 libmpc-dev libmpfr-dev ninja-build python3-pip \
  && git clone --branch trunk --single-branch git://gcc.gnu.org/git/gcc.git \
  && cd gcc && git checkout ${image_version} && cd .. \
  && mkdir /build && cd /build \
  && /gcc/configure --disable-multilib --enable-languages=c,c++,lto \
  && make --jobs $(nproc) \
  && make install \
  && apt-get purge --autoremove --yes flex g++ gcc libgmp-dev libmpc-dev libmpfr-dev \
  && apt-get install --no-install-recommends --quiet --yes libc6-dev \
  && rm -rf /gcc /build /var/lib/apt/lists/*

RUN pip install "conan==2.24.0" --break-system-packages --no-cache-dir

COPY .clang-tidy /

# configure Conan
ENV CONAN_HOME=/tmp/conan
COPY .devcontainer/base-gcc/conan-config /tmp/conan-config
RUN conan config install /tmp/conan-config
RUN conan profile detect --force
