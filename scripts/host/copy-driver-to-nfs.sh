#!/bin/bash
DRIVER_NAME="ssd1306.ko"
PATH_TO_DRIVER="../../build/tmp/work/beaglebone_yocto-poky-linux-gnueabi/ssd1306/1.0/package/lib/modules/6.1.20-yocto-standard/extra/${DRIVER_NAME}"
PATH_TO_NFS="/nfs/beaglebone/lib/modules/6.1.20-yocto-standard/extra"

# Ensure the NFS directory exists
if [ ! -d "${PATH_TO_NFS}" ]; then
    echo "Creating NFS directory at ${PATH_TO_NFS}"
    sudo mkdir -p "${PATH_TO_NFS}"
fi

# Copy the driver to the NFS directory
echo "Copying ${DRIVER_NAME} to NFS directory..."
sudo cp "${PATH_TO_DRIVER}" "${PATH_TO_NFS}"

if [ $? -eq 0 ]; then
    echo "Successfully copied ${DRIVER_NAME} to NFS directory."
else
    echo "Failed to copy ${DRIVER_NAME} to NFS directory."
fi
