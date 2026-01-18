FROM ghcr.io/johnmcfarlane/simple-cpp/base-clang:4

ENV BUILD_DIR=/tmp/build

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=clang-debug \
    .

RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
