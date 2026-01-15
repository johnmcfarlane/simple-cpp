FROM ghcr.io/johnmcfarlane/clang:latest

WORKDIR $BUILD_DIR
COPY .devcontainer/prep-build-dir conanfile.txt .
RUN ./prep-build-dir clang-test
