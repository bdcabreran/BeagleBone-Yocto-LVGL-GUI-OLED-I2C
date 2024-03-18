#!/bin/bash

# Prevent this script from running before the TFTP server is properly set up.
# This script is intended to run on the main host device, not within a Docker container.

# Define the TFTP directory where files will be copied.
TFTP_DIRECTORY="/var/lib/tftpboot"

# Display the current TFTP server configuration.
echo "Reading TFTP default configuration..."
sudo cat /etc/default/tftpd-hpa
echo ""

# Path to the directory containing the images to be copied.
IMAGE_PATH="../../build/tmp/deploy/images/beaglebone-yocto/"

# Specify the filenames of the files needed for TFTP boot.
# Modify this list based on your specific needs.
files_of_interest=(
    "zImage"
    "am335x-boneblack.dtb"
    "MLO"
    "u-boot.img"
)

echo "Copying files of interest to TFTP server directory..."

# Iterate over the array of files and copy each one to the TFTP_DIRECTORY.
for file in "${files_of_interest[@]}"; do
    # Using glob patterns to match and copy all relevant versions of the files.
    sudo cp ${IMAGE_PATH}${file}* "${TFTP_DIRECTORY}/"
done

echo "Files have been copied."

# Restart the TFTP server to apply any changes.
echo "Restarting the TFTP Server..."
sudo systemctl restart tftpd-hpa

# Optionally, display the status to confirm the service is running correctly.
echo "Displaying TFTP Server status..."
sudo systemctl status tftpd-hpa.service
