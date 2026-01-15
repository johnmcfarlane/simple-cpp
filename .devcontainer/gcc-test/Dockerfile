FROM ghcr.io/johnmcfarlane/gcc:latest

WORKDIR $BUILD_DIR
COPY .devcontainer/prep-build-dir conanfile.txt .
RUN ./prep-build-dir gcc-test
