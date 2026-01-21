ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG base_image
ARG profile=error-missing-profile-arg
ENV BUILD_DIR=/tmp/build

COPY .devcontainer/base-clang/x86_64-unknown-linux-gnu.conf /etc/ld.so.conf.d/x86_64-unknown-linux-gnu.conf

# RUN cmake --build /build
RUN apt-get remove --quiet --yes \
      clang \
      g++ \
      gcc \
      lld 
# RUN cmake --build /build --target install
RUN apt-get remove --quiet --yes \
      libc++-19-dev \
      libc++1-19 \
      libunwind-19-dev
# RUN apt-get purge --quiet --yes --autoremove \
#       libc++-dev \
#       libc++1 \
#       libunwind-dev

ENV CC=/usr/local/bin/clang
ENV CXX=/usr/local/bin/clang++

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
ENV CONAN_HOME=/tmp/conan
COPY .devcontainer/${base_image}/conan-config /tmp/conan-config
RUN conan config install /tmp/conan-config
RUN conan profile detect --force

# install dependencies
COPY conanfile.txt .
# RUN conan install \
#     --build="*" \
#     --generator=CMakeDeps \
#     --generator=CMakeToolchain \
#     --output-folder="$BUILD_DIR" \
#     --profile=${profile} \
#     .

# # append dev environment script to user environment script
# RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
