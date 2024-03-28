#!/bin/bash

# Check for device argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <device>"
    echo "Example: $0 /dev/sda"
    exit 1
fi

DEVICE=$1

# Safety prompt to prevent accidental execution
echo "This script will write the Yocto image to $DEVICE (SD card)."
echo "Ensure that $DEVICE is the correct SD card device and that it is not mounted."
read -p "Are you sure you want to proceed? (y/N): " confirmation

if [[ $confirmation != "y" && $confirmation != "Y" ]]; then
    echo "Operation canceled."
    exit 1
fi

# Define the path to the image file
IMAGE_PATH="../../build/tmp/deploy/images/beaglebone-yocto/core-image-minimal-beaglebone-yocto.rootfs.wic"

# Check if the image file exists
if [ ! -f "$IMAGE_PATH" ]; then
    echo "Image file not found: $IMAGE_PATH"
    exit 1
fi

# Unmount the device if mounted
echo "Attempting to unmount ${DEVICE}*..."
sudo umount ${DEVICE}* 2>/dev/null

# Write the image to the SD card
echo "Writing image to $DEVICE. Please wait..."
sudo dd if=$IMAGE_PATH of=$DEVICE bs=4M status=progress oflag=sync

echo "Syncing..."
sync

echo "Image successfully written to $DEVICE. You can now safely remove the SD card."
