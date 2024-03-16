# Use Ubuntu 18.04 LTS as base image
FROM ubuntu:18.04

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install Yocto Project prerequisites (based on the official Yocto Project Quick Start)
RUN apt-get update && apt-get install -y \
    gawk wget git-core diffstat unzip texinfo gcc-multilib \
    build-essential chrpath socat cpio python3 python3-pip python3-pexpect \
    xz-utils debianutils iputils-ping libsdl1.2-dev xterm \
    locales sudo bash-completion command-not-found software-properties-common \
    pylint3 python3-subunit mesa-common-dev python2.7 sudo nano gedit vim tree liblz4-tool zstd \
    minicom

# Set the locale
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Clean up APT when done
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Create a non-root user 'devuser' with sudo access
RUN useradd -m devuser && \
    echo "devuser:devuser" | chpasswd && \
    usermod -aG sudo devuser

# Set work directory
WORKDIR /yocto

# Switch to your non-root user
USER devuser

RUN git config --global user.email "bdcabreran@unal.edu.co" && \
    git config --global user.name "bdcabreran"

# Default command
CMD ["/bin/bash"]
