
# Setting Up an NFS Server for BeagleBone Black Development

This guide covers setting up an NFS (Network File System) server on a Linux host PC. The NFS server will share a directory over the network that the BeagleBone Black can mount as its root filesystem during boot. This setup streamlines development by allowing for immediate testing of filesystem changes without needing to flash the BeagleBone Black's storage.

## Install NFS Server

### On Debian-based distributions (Ubuntu, Debian, etc.):

```bash
sudo apt-get update
sudo apt-get install nfs-kernel-server
```


## Configure the Shared Directory

1. **Create a Share Directory**: This directory will act as the root filesystem for the BeagleBone Black.

    ```bash
    sudo mkdir -p /nfs/beaglebone
    ```

2. **Set Permissions**: Ensure the directory is accessible.

    ```bash
    sudo chmod -R 755 /nfs/beaglebone
    sudo chown nobody:nogroup /nfs/beaglebone
    ```

## Export the Shared Directory

1. **Edit the NFS Export File**:

    ```bash
    sudo nano /etc/exports
    ```

2. **Add the Shared Directory** to the file:

    Replace `/nfs/beaglebone` with your directory's path and `192.168.1.2` with your BeagleBone Black's IP address.

    ```
    /nfs/beaglebone 192.168.1.2(rw,sync,no_subtree_check,no_root_squash)
    ```

3. **Apply the Changes**:

    ```bash
    sudo exportfs -ra
    sudo systemctl restart nfs-kernel-server
    ```

4. **Check the service is up and running**: 

    ```bash
    sudo systemctl status nfs-kernel-server
    ```

## Adjust Firewall Settings (If Applicable)

- Allow NFS traffic through the firewall.

    ```bash
    sudo ufw allow from 192.168.1.0/24 to any port nfs
    ```

    Adjust the IP range according to your network setup.

## Testing the NFS Server

Ensure the NFS server is correctly set up and accessible by mounting the shared directory on another Linux machine or the BeagleBone Black.

1. **Mount the Shared Directory**:

    ```bash
    mount -t nfs [PC_IP_ADDRESS]:/nfs/beaglebone /mnt
    ```

2. **Verify the Contents**:

    Check that you can see the shared directory's contents in `/mnt`.

3. **Unmount After Testing**:

    ```bash
    sudo umount /mnt
    ```

With the NFS server configured, you're now ready to proceed with booting the BeagleBone Black using the shared root filesystem. This setup simplifies development workflows by allowing immediate testing of changes to the filesystem without the need for flashing.
