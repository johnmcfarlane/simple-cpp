FROM gcc:trixie

RUN apt-get update --quiet \
  && apt-get upgrade --yes \
  && apt-get install --no-install-recommends --quiet --yes gdb ninja-build python3-pip \
  && apt-get --quiet --yes autoremove \
  && rm -rf /gcc /build /var/lib/apt/lists/*

RUN pip install "cmake~=4.2.1" "conan~=2.24.0" --break-system-packages --no-cache-dir

COPY .devcontainer/images/gcc/conan-config /tmp/conan-config

ENV BUILD_DIR=/tmp/build
ENV CONAN_HOME=/tmp/conan
