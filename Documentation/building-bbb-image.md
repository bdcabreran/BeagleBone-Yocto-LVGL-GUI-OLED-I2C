
---

# Building an Embedded Linux Image for BeagleBone with Yocto Project

This guide provides a concise set of instructions to build an embedded Linux image for BeagleBone boards, specifically tailored for the TI AM335x CPU using the Yocto Project. Follow these steps to set up your environment, build your image, and flash it onto a microSD card for your BeagleBone board.

## Prerequisites

- A Linux-based operating system
- Basic knowledge of terminal and command-line operations
- Installed dependencies for the Yocto Project (see the [Yocto Project Quick Start](https://docs.yoctoproject.org/brief-yoctoprojectqs/index.html) for more details)

## Getting Started

1. **Clone the Yocto Project Repository**

   Begin by cloning the Yocto Project repository `poky` branch `nanbield`.

   ```bash
   git clone -b nanbield https://git.yoctoproject.org/git/poky
   ```

2. **Initialize the Build Environment**

   Source the Yocto Project environment setup script to initialize the build environment.

   ```bash
   source poky/oe-init-build-env
   ```

   This command creates a new build directory and sets up the necessary environment variables. You'll be automatically moved into the `build` directory.

## Building the Image

With the build environment set up, proceed to build the image for the BeagleBone board.

1. **Set the Target Machine**

   Specify the target machine (`beaglebone-yocto`) in your build configuration.

   ```bash
   bitbake core-image-minimal
   ```

2. **Build Process**

   The `bitbake` command initiates the build process for the `core-image-minimal`, which is a minimal Linux image suitable for BeagleBone boards. This process may take some time depending on your system's capabilities.

## Flashing the Image

After the build process is complete, the next step is to flash the generated image onto a microSD card.

0. **Use `write-to-sdcard.sh` script**

    In case you want to automate the creation of a booteable sd-card please refer to the script [`write-to-sdcard.sh`](../scripts/host/write-to-sdcard.sh) located under `/yocto/scripts/host` and check its readme file at `/yocto/Documentation/write-to-sdcard.sh`, otherwise you can follow steps 1 and 2. 

1. **Navigate to the Images Directory**

   Change directory to where the built images are located.

   ```bash
   cd tmp/deploy/images/beaglebone-yocto
   ```

2. **Flash the Image onto the microSD Card**

   Use the `dd` command to flash the built image onto your microSD card (ensure the microSD card is correctly identified, in this example `/dev/mmcblk0`).

   ```bash
   dd if=core-image-minimal-beaglebone-yocto.wic of=/dev/mmcblk0 bs=4M
   ```

   **Warning:** Be very careful with the `dd` command and the target device (`of=` parameter). Selecting the wrong device can overwrite important data.

## Next Steps

- After flashing, insert the microSD card into your BeagleBone board and power it on. The board should boot into the Linux system you've built.
- For customizing images or supporting other boards, refer to the comprehensive [Yocto Project Documentation](https://docs.yoctoproject.org/).

## Conclusion

You've successfully built and flashed an embedded Linux image for the BeagleBone board using the Yocto Project. Explore the possibilities by customizing your build or adding new layers to support additional hardware and features.

---
