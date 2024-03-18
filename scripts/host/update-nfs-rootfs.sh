#!/bin/bash

# Path to the root filesystem tarball from Yocto build output
IMAGE_PATH="../../build/tmp/deploy/images/beaglebone-yocto/core-image-minimal-beaglebone-yocto.rootfs.tar.bz2"
# NFS shared directory path
NFS_PATH="/nfs/beaglebone"

# Remove the existing NFS root filesystem
echo "Removing existing NFS root filesystem..."
sudo rm -rf ${NFS_PATH}

# Recreate the NFS shared directory
echo "Creating NFS shared directory..."
sudo mkdir -p ${NFS_PATH}
sudo chown nobody:nogroup ${NFS_PATH}
sudo chmod 755 ${NFS_PATH}

# Extract the new root filesystem into the NFS shared directory
echo "Extracting new root filesystem to NFS shared directory..."
sudo tar -xjf ${IMAGE_PATH} -C ${NFS_PATH}

echo "Root filesystem has been updated."

# Restart the NFS server to apply any changes.
echo "Restarting the NFS server..."
sudo systemctl restart nfs-kernel-server

# Optionally, display the status to confirm the service is running correctly.
echo "Displaying NFS server status..."
sudo systemctl status nfs-kernel-server --no-pager

echo "Update process completed successfully."
