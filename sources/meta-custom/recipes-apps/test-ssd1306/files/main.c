#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <getopt.h>

#define SSD1306_128_64_LINES        64
#define SSD1306_128_32_LINES        32
#define SSD1306_64_48_LINES         48

#define SSD1306_128_64_COLUMNS      128
#define SSD1306_128_32_COLUMNS      128
#define SSD1306_64_48_COLUMNS       64

// Include or define the command and payload structures here
typedef enum {
    SSD1306_CMD_INVALID,
    SSD1306_CMD_SET_ROTATE,         // Corresponds to ssd1306_oled_set_rotate
    SSD1306_CMD_HORIZONTAL_FLIP,    // Corresponds to ssd1306_oled_horizontal_flip
    SSD1306_CMD_DISPLAY_FLIP,       // Corresponds to ssd1306_oled_display_flip
    SSD1306_CMD_CLEAR_SCREEN,       // Corresponds to ssd1306_oled_clear_screen
    SSD1306_CMD_DRAW_PIXEL,         // Corresponds to ssd1306_oled_draw_pixel
    SSD1306_CMD_DRAW_AREA,          // Corresponds to ssd1306_oled_draw_area
    SSD1306_CMD_LAST
}ssd1306_commands_t;

#define IS_VALID_CMD(cmd) (cmd > SSD1306_CMD_INVALID & cmd < SSD1306_CMD_LAST)

typedef struct 
{
    uint8_t  x; 
    uint8_t  y;
    uint8_t  width;
    uint8_t  height;
    uint8_t  data[(SSD1306_128_64_COLUMNS * SSD1306_128_64_LINES) / 8];
} draw_area_payload_t;

typedef struct 
{
    uint8_t  x; 
    uint8_t  y;
    uint8_t  state; // 1-on, 0-off
}draw_pixel_payload_t;

typedef struct
{
    uint8_t angle; // only degree 0 and 180
}rotate_screen_payload_t;

typedef struct
{
    uint8_t state; // 1-on, 0-off
}horizontal_flip_payload_t;

typedef struct
{
    uint8_t state; // 1-on, 0-off
}display_flip_payload_t;


typedef union 
{
    draw_pixel_payload_t    draw_pixel;
    draw_area_payload_t     draw_area;
    rotate_screen_payload_t rotate;
    horizontal_flip_payload_t horizontal_flip;
    display_flip_payload_t  display_flip;
}payload_u;

typedef struct {
    ssd1306_commands_t command;
    uint16_t length;
    payload_u payload;
} ssd1306_command_data_t;

#define MAX_COMMAND_SIZE sizeof(ssd1306_command_data_t)

typedef union ssd1306_data_packet {
    ssd1306_command_data_t data;
    uint8_t raw[MAX_COMMAND_SIZE];
} ssd1306_data_packet_u;

#define MIN_VALID_VALUE 0
#define MAX_VALID_VALUE 255

void print_usage() {
    printf("Usage:\n");
    printf("  -h        Help (shows this usage information)\n");
    printf("  -c        Clear screen (no additional parameters required)\n");
    printf("  -r <angle> Set rotate angle (0 or 180)\n");
    printf("  -f <state> Display flip (1 or 0 for on/off)\n");
    printf("  -z <state> Horizontal flip (1 or 0 for on/off)\n");
    printf("  -p <X> <Y> <state> Set pixel at X,Y with state S (1 for on, 0 for off)\n");
    printf("  -a <X> <Y> <W> <H> <data> Draw area at X,Y with width W, height H, and data index I\n");
    printf("            X and Y specify the top-left corner of the area.\n");
    printf("            W and H specify the width and height of the area.\n");
    printf("            <data> should be a binary representation of the image data,\n");
    printf("            encoded in a way that matches the driver's expectations.\n");
}


void handle_c_command(int argc, char *argv[], ssd1306_command_data_t *packet);
void handle_r_command(int argc, char *argv[], ssd1306_command_data_t *packet);
void handle_f_command(int argc, char *argv[], ssd1306_command_data_t *packet);
void handle_z_command(int argc, char *argv[], ssd1306_command_data_t *packet);
void handle_p_command(int argc, char *argv[], ssd1306_command_data_t *packet);
void handle_a_command(int argc, char *argv[], ssd1306_command_data_t *packet);



int is_cmd(int argc, char **argv, char *cmd)
{
    if (strcmp(argv[1], cmd) == 0)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv) {
    int fd, opt;
    char *device_path = "/dev/ssd1306";
    ssd1306_command_data_t packet = {0};

    if (is_cmd(argc, argv, "-p")) {
        handle_p_command(argc, argv, &packet);
    } 
    else if (is_cmd(argc, argv, "-r")){
        handle_r_command(argc, argv, &packet);
    }
    else if (is_cmd(argc, argv, "-a")){
       handle_a_command(argc, argv, &packet); 
    }
    else if (is_cmd(argc, argv, "-c")){
       handle_c_command(argc, argv, &packet); 
    }  
    else if (is_cmd(argc, argv, "-f")){
       handle_f_command(argc, argv, &packet); 
    }      
    else if (is_cmd(argc, argv, "-z")){
       handle_z_command(argc, argv, &packet); 
    }  
    else if (is_cmd(argc, argv, "-h")){
        print_usage();
    }
    else {
        print_usage();
    }


    if (!IS_VALID_CMD(packet.command)) {
        return EXIT_FAILURE;
    }

    // Open the device
    fd = open(device_path, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    // Calculate the total size to write based on the command
    size_t write_size = sizeof(packet.command) + sizeof(packet.length) + packet.length;

    if (write(fd, &packet, write_size) < 0) {
        perror("Failed to write command to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Command sent to %s\n", device_path);
    close(fd);
    return EXIT_SUCCESS;
}



void handle_c_command(int argc, char *argv[], ssd1306_command_data_t *packet)
{
    packet->command = SSD1306_CMD_CLEAR_SCREEN;
    packet->length = 0;
}


void handle_r_command(int argc, char *argv[], ssd1306_command_data_t *packet)
{
    if (argc != 3) {
        fprintf(stderr, "Not enough arguments for -r option\n");
        print_usage();
        return;
    }

    packet->command = SSD1306_CMD_SET_ROTATE;
    packet->length = sizeof(rotate_screen_payload_t);

    int angle = atoi(argv[2]);
    // Validate the angle argument
    if (angle == 0 || angle == 180) {
        packet->payload.rotate.angle = (uint8_t)angle;
    } else {
        fprintf(stderr, "Invalid argument for -r option. Must be 0 or 180.\n");
        print_usage();
        return;
    }

    printf("Parsed value for -r: %d\n", angle);
}

void handle_p_command(int argc, char *argv[], ssd1306_command_data_t *packet)
{
    if (argc != 5) {
        fprintf(stderr, "Not enough arguments for -p option\n");
        print_usage();
        return;
    }
    int value1 = atoi(argv[2]);
    int value2 = atoi(argv[3]);
    int value3 = atoi(argv[4]);

    // Assignment after validation
    packet->command = SSD1306_CMD_DRAW_PIXEL;
    packet->length = sizeof(draw_pixel_payload_t);
    packet->payload.draw_pixel.x = (uint8_t)value1;
    packet->payload.draw_pixel.y = (uint8_t)value2;
    packet->payload.draw_pixel.state = (uint8_t)value3;

    printf("Parsed values for -p: %d %d %d\n", value1, value2, value3);
}

void handle_a_command(int argc, char *argv[], ssd1306_command_data_t *packet)
{
    if (argc != 7) {
        fprintf(stderr, "Not enough arguments for -a option\n");
        print_usage();
        return;
    }

    packet->command = SSD1306_CMD_DRAW_AREA;
    packet->length = sizeof(draw_area_payload_t); // Ensure this struct exists and is correctly sized
    packet->payload.draw_area.x = (uint8_t)atoi(argv[2]);
    packet->payload.draw_area.y = (uint8_t)atoi(argv[3]);
    packet->payload.draw_area.width = (uint8_t)atoi(argv[4]);
    packet->payload.draw_area.height = (uint8_t)atoi(argv[5]);

    printf("Parsed value for -a: %d %d %d %d %d\n", packet->payload.draw_area.x, \
    packet->payload.draw_area.y, packet->payload.draw_area.width, packet->payload.draw_area.height);
}

void handle_f_command(int argc, char *argv[], ssd1306_command_data_t *packet){

    if (argc != 3) {
        fprintf(stderr, "Not enough arguments for -f option\n");
        print_usage();
        return;
    }

    packet->command = SSD1306_CMD_HORIZONTAL_FLIP;
    packet->length = sizeof(horizontal_flip_payload_t);

    int state = atoi(argv[2]);
    // Validate the state argument
    if (state == 0 || state == 1) {
        packet->payload.horizontal_flip.state = (uint8_t)state;
    } else {
        fprintf(stderr, "Invalid argument for -f option. Must be 0 or 1.\n");
        print_usage();
        return;
    }

}


void handle_z_command(int argc, char *argv[], ssd1306_command_data_t *packet){
    if (argc != 3) {
        fprintf(stderr, "Not enough arguments for -z option\n");
        print_usage();
        return;
    }

    packet->command = SSD1306_CMD_DISPLAY_FLIP;
    packet->length = sizeof(horizontal_flip_payload_t);

    int state = atoi(argv[2]);
    // Validate the state argument
    if (state == 0 || state == 1) {
        packet->payload.display_flip.state = (uint8_t)state;
    } else {
        fprintf(stderr, "Invalid argument for -z option. Must be 0 or 1.\n");
        print_usage();
        return;
    }
}