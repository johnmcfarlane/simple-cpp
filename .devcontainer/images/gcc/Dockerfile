FROM mcr.microsoft.com/devcontainers/base:trixie

RUN apt-get update --quiet \
  && apt-get upgrade \
  && apt-get install --no-install-recommends --quiet --yes binutils build-essential flex gcc-multilib gnulib libgmp-dev libmpc3 libmpc-dev libmpfr-dev ninja-build python3-pip \
  && git clone --depth 1 git://gcc.gnu.org/git/gcc.git \
  && mkdir /build \
  && cd /build \
  && /gcc/configure --disable-multilib --enable-languages=c,c++,lto \
  && make --jobs $(nproc) \
  && make install
RUN apt-get purge --autoremove --yes flex g++ gcc libgmp-dev libmpc-dev libmpfr-dev \
  && apt-get install --no-install-recommends --quiet --yes gdb libmpc3 \
  && apt-get --quiet --yes autoremove \
  && rm -rf /gcc /build /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/g++ g++ /usr/local/bin/g++ 10 \
  && update-alternatives --install /usr/bin/gcc gcc /usr/local/bin/gcc 10 \
  && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 10 \
  && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 10
ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++
ENV LD_LIBRARY_PATH=/usr/local/lib64/

RUN pip install "cmake~=4.2.1" "conan~=2.24.0" --break-system-packages --no-cache-dir

COPY .devcontainer/images/gcc/conan-config /tmp/conan-config
