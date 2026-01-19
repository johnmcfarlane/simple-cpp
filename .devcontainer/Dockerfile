ARG base_image
FROM ghcr.io/johnmcfarlane/simple-cpp/$base_image

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
