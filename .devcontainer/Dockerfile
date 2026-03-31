ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG base_image
ARG profile=error-missing-profile-arg

RUN groupadd --gid 1000 tux \
    && useradd --create-home --gid 1000 --shell /bin/bash --uid 1000 tux
USER tux

ENV BUILD_DIR=/home/tux/build

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
COPY --chown=tux .devcontainer/${base_image}/conan-config /home/tux/conan-config
RUN conan config install /home/tux/conan-config
RUN rm -rf /home/tux/conan-config
RUN conan profile detect --force

# install dependencies
COPY --chown=tux conanfile.txt /home/tux
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=${profile} \
    /home/tux
RUN rm /home/tux/conanfile.txt

# append dev environment script to user environment script
RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
