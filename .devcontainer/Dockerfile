ARG base_image
ARG base_image_version
FROM ghcr.io/johnmcfarlane/simple-cpp/$base_image:$base_image_version

ARG profile

ENV BUILD_DIR=/tmp/build

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=$profile \
    .

RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
