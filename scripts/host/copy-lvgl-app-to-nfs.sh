#!/bin/bash

APP_NAME="lvgl_fb"
PATH_TO_DRIVER="../../build/tmp/work/cortexa8hf-neon-poky-linux-gnueabi/lvgl-demo-fb/8.3.0/lvgl-demo-fb-8.3.0/${APP_NAME}"
PATH_TO_NFS="/nfs/beaglebone/usr/bin"

# Ensure the NFS directory exists
if [ ! -d "${PATH_TO_NFS}" ]; then
    echo "Creating NFS directory at ${PATH_TO_NFS}"
    sudo mkdir -p "${PATH_TO_NFS}"
fi

# Copy the driver to the NFS directory
echo "Copying ${APP_NAME} to NFS directory..."
sudo cp "${PATH_TO_DRIVER}" "${PATH_TO_NFS}"

if [ $? -eq 0 ]; then
    echo "Successfully copied ${APP_NAME} to NFS directory."
else
    echo "Failed to copy ${APP_NAME} to NFS directory."
fi




