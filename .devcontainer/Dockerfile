ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG base_image
ARG profile=error-missing-profile-arg
ENV BUILD_DIR=/tmp/build

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
ENV CONAN_HOME=/tmp/conan
COPY .devcontainer/${base_image}/conan-config /tmp/conan-config
RUN conan config install /tmp/conan-config
RUN conan profile detect --force

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=${profile} \
    .

# append dev environment script to user environment script
RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
