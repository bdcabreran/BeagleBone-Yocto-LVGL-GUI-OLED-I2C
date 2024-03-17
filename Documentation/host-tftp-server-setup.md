
# TFTP Server Setup and Configuration Guide

This guide provides instructions on how to set up a TFTP (Trivial File Transfer Protocol) server on a Linux machine, configure it, and test the setup by transferring a file to a BeagleBone device.

## 1. Installation

To install the TFTP server, follow these steps:

1. Update the package lists for upgrades and new package installations:

   ```bash
   sudo apt update
   ```

2. Install the `tftpd-hpa` package:

   ```bash
   sudo apt-get install tftpd-hpa
   ```

## 2. Verification

After the installation is complete, verify that the TFTP server is running:

```bash
sudo systemctl status tftpd-hpa.service
```

You should see output indicating that the `tftpd-hpa.service` is active and running.

## 3. Configuration

### 3.1 Configuring the TFTP Server

The default configuration files are located at `/etc/default/tftpd-hpa`. You'll need to customize some settings:

1. Open the default configuration file:

   ```bash
   sudo vi /etc/default/tftpd-hpa
   ```

2. Customize the configuration. Set the TFTP directory, address, username, and options as follows:

   - `TFTP_USERNAME="tftp"`
   - `TFTP_DIRECTORY="/var/lib/tftpboot"`
   - `TFTP_ADDRESS="0.0.0.0:69"`
   - `TFTP_OPTIONS="--secure"`

3. Create the TFTP directory:

   ```bash
   sudo mkdir /var/lib/tftpboot
   ```

4. Set the directory permissions and ownership:

   ```bash
   sudo chmod -R 777 /var/lib/tftpboot
   sudo chown -R nobody:nogroup /var/lib/tftpboot
   ```

5. Restart the TFTP server to apply the changes:

   ```bash
   sudo systemctl restart tftpd-hpa
   ```

### 3.2 Testing the Configurations

To test your TFTP server setup:

1. Create a dummy file on the server host PC.

2. Copy it to the BeagleBone using the TFTP command:

   ```bash
   root@beaglebone-yocto:~# tftp -r hello.txt -g 192.168.1.1
   root@beaglebone-yocto:~# ls
   hello.txt
   ```

   This command downloads `hello.txt` from the TFTP server to the BeagleBone.

Congratulations! You have successfully set up and tested your TFTP server.
