FROM ghcr.io/johnmcfarlane/simple-cpp/base-clang:4

ENV BUILD_DIR=/tmp/build
WORKDIR $BUILD_DIR

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build=missing \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=clang-release \
    .

RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
