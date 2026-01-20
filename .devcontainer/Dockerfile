ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG profile=error-missing-profile-arg
ENV BUILD_DIR=/tmp/build

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=${profile} \
    .

RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
