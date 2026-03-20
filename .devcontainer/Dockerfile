ARG base_image=error-missing-base_image-arg
ARG base_image_version=error-missing-base_image_version-arg
FROM ghcr.io/johnmcfarlane/simple-cpp/${base_image}:${base_image_version}

ARG base_image
ARG profile=error-missing-profile-arg
ENV BUILD_DIR=/tmp/build

# Create the user, from
# https://code.visualstudio.com/remote/advancedcontainers/add-nonroot-user#_creating-a-nonroot-user
ARG USERNAME=user-name-goes-here
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

USER $USERNAME
ENV HOME=/home/$USERNAME

# set system wide Clang-Tidy configuration
COPY .clang-tidy /

# configure Conan
COPY .devcontainer/${base_image}/conan-config $HOME/conan-config
RUN conan config install $HOME/conan-config
RUN conan profile detect --force

# install dependencies
COPY conanfile.txt .
RUN conan install \
    --build="*" \
    --generator=CMakeDeps \
    --generator=CMakeToolchain \
    --output-folder="$BUILD_DIR" \
    --profile=${profile} \
    .

# append dev environment script to user environment script
RUN cat $BUILD_DIR/conanbuild.sh >> ~/.bashrc
