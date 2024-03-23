#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <getopt.h>


int main(int argc, char **argv) {
    int fd, opt;
    char *device_path = "/dev/ssd1306";
    // ssd1306_command_data_t packet = {0};

    printf("Hwllo world\n");

    // Open the device
    fd = open(device_path, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    close(fd);
    return EXIT_SUCCESS;
}
