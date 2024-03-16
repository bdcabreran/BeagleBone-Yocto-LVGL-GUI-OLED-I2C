# Use Ubuntu 20.04 LTS as base image
FROM ubuntu:20.04

# Avoid prompts from apt by setting it to non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Install Yocto Project prerequisites (based on the official Yocto Project Quick Start for newer branches)
RUN apt-get update && apt-get install -y \
    gawk wget git-core diffstat unzip texinfo gcc-multilib \
    build-essential chrpath socat cpio python3 python3-pip python3-pexpect \
    xz-utils debianutils iputils-ping libsdl1.2-dev xterm \
    locales sudo bash-completion software-properties-common \
    pylint python3-subunit mesa-common-dev vim nano tree liblz4-tool zstd \
    minicom

# Set the locale to avoid any locale issues during the build
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Clean up APT when done to reduce image size
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Create a non-root user 'devuser' with sudo access for Yocto builds
RUN useradd -m devuser && \
    echo "devuser:devuser" | chpasswd && \
    usermod -aG sudo devuser

# Set the working directory to where Yocto builds will take place
WORKDIR /yocto

# Switch to your non-root user to avoid using root for Yocto builds
USER devuser

# Global Git configuration settings
RUN git config --global user.email "bdcabreran@unal.edu.co" && \
    git config --global user.name "bdcabreran"

# Default command to keep the container running
CMD ["/bin/bash"]
