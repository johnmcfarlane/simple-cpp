FROM ghcr.io/johnmcfarlane/simple-cpp/base-gcc:1

ENV BUILD_DIR=/tmp/build

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=gcc-test \
    .

RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
