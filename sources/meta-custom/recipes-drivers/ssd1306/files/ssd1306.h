#ifndef __SSD1306_H__
#define __SSD1306_H__

#define SSD1306_I2C_ADDR            0x3c

#define SSD1306_COMM_CONTROL_BYTE   0x00
#define SSD1306_DATA_CONTROL_BYTE   0x40

#define SSD1306_COMM_DISPLAY_OFF    0xae
#define SSD1306_COMM_DISPLAY_ON     0xaf
#define SSD1306_COMM_HORIZ_NORM     0xa0
#define SSD1306_COMM_HORIZ_FLIP     0xa1
#define SSD1306_COMM_RESUME_RAM     0xa4
#define SSD1306_COMM_IGNORE_RAM     0xa5
#define SSD1306_COMM_DISP_NORM      0xa6
#define SSD1306_COMM_DISP_INVERSE   0xa7
#define SSD1306_COMM_MULTIPLEX      0xa8
#define SSD1306_COMM_VERT_OFFSET    0xd3
#define SSD1306_COMM_CLK_SET        0xd5
#define SSD1306_COMM_PRECHARGE      0xd9
#define SSD1306_COMM_COM_PIN        0xda
#define SSD1306_COMM_DESELECT_LV    0xdb
#define SSD1306_COMM_CONTRAST       0x81
#define SSD1306_COMM_DISABLE_SCROLL 0x2e
#define SSD1306_COMM_ENABLE_SCROLL  0x2f
#define SSD1306_COMM_PAGE_NUMBER    0xb0
#define SSD1306_COMM_LOW_COLUMN     0x00
#define SSD1306_COMM_HIGH_COLUMN    0x10

#define SSD1306_COMM_START_LINE     0x40

#define SSD1306_COMM_CHARGE_PUMP    0x8d

#define SSD1306_COMM_SCAN_NORM      0xc0
#define SSD1306_COMM_SCAN_REVS      0xc8

#define SSD1306_COMM_MEMORY_MODE    0x20
#define SSD1306_COMM_SET_COL_ADDR   0x21
#define SSD1306_COMM_SET_PAGE_ADDR  0x22

#define SSD1306_HORI_MODE           0x00
#define SSD1306_VERT_MODE           0x01
#define SSD1306_PAGE_MODE           0x02

#define SSD1306_FONT_SMALL          0x00
#define SSD1306_FONT_NORMAL         0x01

#define SSD1306_128_64_LINES        64
#define SSD1306_128_32_LINES        32
#define SSD1306_64_48_LINES         48

#define SSD1306_128_64_COLUMNS      128
#define SSD1306_128_32_COLUMNS      128
#define SSD1306_64_48_COLUMNS       64

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

#define MAX_COMMAND_SIZE sizeof(ssd1306_command_data_t) // Define according to the actual size required

typedef union ssd1306_data_packet {
    ssd1306_command_data_t data;
    uint8_t raw[MAX_COMMAND_SIZE];
} ssd1306_data_packet_u;

#endif