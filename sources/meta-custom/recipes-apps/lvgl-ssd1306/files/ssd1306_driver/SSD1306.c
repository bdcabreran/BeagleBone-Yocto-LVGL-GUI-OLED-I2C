#include "SSD1306.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


// Include or define the command and payload structures here
typedef enum {
    SSD1306_CMD_INVALID,
    SSD1306_CMD_SET_ROTATE,         // Corresponds to ssd1306_oled_set_rotate
    SSD1306_CMD_HORIZONTAL_FLIP,    // Corresponds to ssd1306_oled_horizontal_flip
    SSD1306_CMD_DISPLAY_FLIP,       // Corresponds to ssd1306_oled_display_flip
    SSD1306_CMD_CLEAR_SCREEN,       // Corresponds to ssd1306_oled_clear_screen
    SSD1306_CMD_DRAW_PIXEL,         // Corresponds to ssd1306_oled_draw_pixel
    SSD1306_CMD_DRAW_AREA,          // Corresponds to ssd1306_oled_draw_area
    SSD1306_CMD_DRAW_GIF,
    SSD1306_CMD_LAST
}ssd1306_commands_t;

#define IS_VALID_CMD(cmd) (cmd > SSD1306_CMD_INVALID & cmd < SSD1306_CMD_LAST)

typedef struct 
{
    uint8_t  x; 
    uint8_t  y;
    uint8_t  w;
    uint8_t  h;
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

typedef struct
{
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
    uint8_t  gif_index;
    uint16_t frame_count;
    uint16_t frame_size;
}gif_payload_t;

typedef union 
{
    draw_pixel_payload_t    draw_pixel;
    draw_area_payload_t     draw_area;
    rotate_screen_payload_t rotate;
    horizontal_flip_payload_t horizontal_flip;
    display_flip_payload_t  display_flip;
    gif_payload_t           display_gif;
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

ssd1306_command_data_t packet = {0};
static int fd = -1;

void ssd1306_init(void) {
    char *device_path = "/dev/ssd1306";

    fd = open(device_path, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open the OLED device");
        // Handle error
    }
    // Additional initialization for SSD1306, if required
}



void convert_lvgl_color_8bit_to_ssd1306(const lv_color_t *color_map, uint8_t *data, lv_area_t area) {
    int area_width = area.x2 - area.x1 + 1;
    int area_height = area.y2 - area.y1 + 1;

    // Clearing the data array to make sure it's all zeros to start with
    memset(data, 0, (area_width + 7) / 8 * area_height);

    for (int y = 0; y < area_height; y++) {
        for (int x = 0; x < area_width; x++) {
            int pixel_index = x + (y * area_width);
            lv_color_t color = color_map[pixel_index];
            int byte_index = (y * ((area_width + 7) / 8)) + (x / 8);
            int bit_index = 7 - (x % 8);

            // Convert RGB332 to grayscale
            uint8_t red = (color.ch.red * 255) / 7;   // Scale 3-bit red to 8-bit
            uint8_t green = (color.ch.green * 255) / 7; // Scale 3-bit green to 8-bit
            uint8_t blue = (color.ch.blue * 255) / 3;  // Scale 2-bit blue to 8-bit

            // Convert to grayscale using a simple averaging method
            uint8_t gray = (red + green + blue) / 3;

            // Determine if the pixel should be on or off based on a threshold
            if (gray > 128) {
                data[byte_index] |= (1 << bit_index);
            } else {
                data[byte_index] &= ~(1 << bit_index);
            }
        }
    }
}


void ssd1306_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map) {

    if (fd < 0) {
        printf("OLED device not open\n");
        return;
    }

    // Initialize the draw_area_payload part of the packet
    packet.command = SSD1306_CMD_DRAW_AREA;
    packet.length = sizeof(draw_area_payload_t); 
    packet.payload.draw_area.x = area->x1;
    packet.payload.draw_area.y = area->y1;
    packet.payload.draw_area.w = area->x2 - area->x1 + 1;
    packet.payload.draw_area.h = area->y2 - area->y1 + 1;


   // Prepare the pixel data for SSD1306
    uint8_t data[(SSD1306_128_64_COLUMNS * SSD1306_128_64_LINES) / 8] = {0};
    // convert_lvgl_color_to_ssd1306(color_map, packet.payload.draw_area.data, *area);
    convert_lvgl_color_8bit_to_ssd1306(color_map, packet.payload.draw_area.data, *area);

    // Write the packet to the device
    size_t write_size = sizeof(packet.command) + sizeof(packet.length) + packet.length;

    if (write(fd, &packet, write_size) < 0) {
        perror("Failed to write command to the device");
    }

    lv_disp_flush_ready(drv);
}
