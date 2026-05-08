ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG base_image
ARG profile=error-missing-profile-arg

RUN groupadd --gid 1000 tux \
    && useradd --create-home --gid 1000 --shell /bin/bash --uid 1000 tux \
    && echo tux ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/tux \
    && chmod 0440 /etc/sudoers.d/tux
USER tux

ENV BUILD_DIR=/home/tux/build

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
COPY --chown=tux .devcontainer/${base_image}/conan-config /home/tux/conan-config
RUN conan config install /home/tux/conan-config
RUN rm -rf /home/tux/conan-config
RUN conan profile detect --force

# configure remote
RUN git clone --branch=simple-cpp --depth=1 https://github.com/johnmcfarlane/conan-center-index.git ~/conan-center-index \
    && cd ~/conan-center-index \
    && git checkout eed65da43
RUN conan remote disable conancenter
RUN conan remote add local ~/conan-center-index

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
