#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/delay.h>  
#include <linux/string.h> 
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h> // For copy_from_user
#include "ssd1306.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bayron Cabrera");
MODULE_DESCRIPTION("A simple Linux Driver for SSD1306 OLED.");
MODULE_VERSION("0.1");

// Device specific structure
struct ssd1306_dev {
    struct i2c_client *client;
    uint8_t max_columns; 
    uint8_t max_lines; 
    uint8_t x; 
    uint8_t y;
    uint8_t data_buff[100];
    uint8_t framebuffer[(SSD1306_128_64_COLUMNS * SSD1306_128_64_LINES) / 8];
};


struct ssd1306_char_dev {
    struct ssd1306_dev ssd1306;     // SSD1306 device
    struct cdev cdev;               // Character device structure
};

static int major_number;
static struct class* ssd1306_class = NULL;
static struct device *ssd1306_device = NULL;
static dev_t dev_num;

////////////////////////////////////////////////////////////////////////////////

static const uint8_t demo_image_width = 62;
static const uint8_t demo_image_height = 64;
static const uint8_t demo_image_data[] = {

    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xD0, 0x02, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFE, 0x00, 0x08, 0x7F, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xF9, 0x55, 0x42, 0x0F, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xE4, 0x00, 0x28, 0x87, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xD1, 0x4A, 0x82, 0x51, 0xFF, 0xFC, 
    0xFF, 0xFF, 0x84, 0x10, 0x28, 0x00, 0xFF, 0xFC, 
    0xFF, 0xFF, 0x11, 0x44, 0x82, 0xAA, 0x3F, 0xFC, 
    0xFF, 0xFE, 0x44, 0x11, 0x24, 0x00, 0xBF, 0xFC, 
    0xFF, 0xFC, 0x11, 0x04, 0x08, 0xAA, 0x0F, 0xFC, 
    0xFF, 0xF9, 0x44, 0x51, 0x42, 0x00, 0x4F, 0xFC, 
    0xFF, 0xF0, 0x11, 0x04, 0x10, 0x95, 0x17, 0xFC, 
    0xFF, 0xF2, 0x84, 0x51, 0x44, 0x40, 0x43, 0xFC, 
    0xFF, 0xE0, 0x21, 0x04, 0x12, 0x12, 0x13, 0xFC, 
    0xFF, 0xCA, 0x94, 0x21, 0x21, 0x04, 0x89, 0xFC, 
    0xFF, 0xC0, 0x03, 0x48, 0x48, 0xF0, 0x41, 0xFC, 
    0xFF, 0xD5, 0x5F, 0xF2, 0x07, 0xFE, 0x28, 0xFC, 
    0xFF, 0x80, 0x7F, 0xF8, 0xAF, 0xFF, 0x05, 0xFC, 
    0xFF, 0x94, 0xFF, 0xFF, 0x7F, 0xFF, 0xA0, 0x7C, 
    0xFF, 0x41, 0xFF, 0xFF, 0xFF, 0xDF, 0xCA, 0x7C, 
    0xFF, 0x15, 0xF8, 0x7F, 0xFF, 0x8F, 0xC0, 0xFC, 
    0xFF, 0x41, 0xF9, 0x7F, 0xFF, 0x2F, 0xEA, 0x7C, 
    0xFF, 0x13, 0xF8, 0x7F, 0xFF, 0x07, 0xE0, 0x3C, 
    0xFF, 0x45, 0xFC, 0xFF, 0xFF, 0x9F, 0xE5, 0x7C, 
    0xFF, 0x13, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x3C, 
    0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xE2, 0x7C, 
    0xFE, 0x57, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0x3C, 
    0xFF, 0x03, 0xFF, 0xFD, 0xBF, 0xFF, 0xE4, 0x7C, 
    0xFF, 0x53, 0xFF, 0xFD, 0x5F, 0xFF, 0xE1, 0x3C, 
    0xFF, 0x09, 0xFF, 0xFE, 0xFF, 0xFF, 0xE8, 0x7C, 
    0xFF, 0x23, 0xFF, 0xFF, 0x5F, 0xFF, 0xE2, 0x7C, 
    0xFF, 0xD7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0x3E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0x1C, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0x3E, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFE, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0x3C, 0x38, 0x87, 0xC7, 0x8E, 0x3C, 0x7C, 
    0xFF, 0x1E, 0x79, 0x23, 0xE7, 0xAF, 0x19, 0x7C, 
    0xFF, 0x3D, 0x38, 0x0B, 0xC7, 0x8F, 0x58, 0xFC, 
    0xFE, 0x5E, 0x79, 0xE1, 0xD7, 0xAF, 0x85, 0xFC, 
    0xFF, 0x1C, 0x78, 0xF5, 0xC7, 0x8F, 0x91, 0xFC, 
    0xFF, 0x3E, 0x39, 0xF1, 0xE7, 0xAF, 0xC7, 0xFC, 
    0xFF, 0x1E, 0xB8, 0xF3, 0xC7, 0x8F, 0xE3, 0xFC, 
    0xFF, 0x3C, 0x79, 0xF1, 0xE7, 0xAF, 0x89, 0xFC, 
    0xFE, 0x5E, 0x78, 0xF3, 0xC7, 0x8F, 0xA3, 0xFC, 
    0xFF, 0x0D, 0x39, 0xF1, 0xE1, 0x2F, 0x18, 0xFC, 
    0xFF, 0x4E, 0x78, 0xF3, 0xE8, 0x0E, 0x58, 0xFC, 
    0xFF, 0x8C, 0x38, 0xF1, 0xE2, 0xCE, 0x3C, 0x7C, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xEF, 0xFF, 0xBC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
};

uint8_t ssd1306_oled_set_rotate(struct ssd1306_dev *dev, uint8_t degree)
{
    uint8_t *data_buf = dev->data_buff;
    uint8_t ret = 0;

    // only degree 0 and 180
    if (degree == 0)
    {
        data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
        data_buf[1] = SSD1306_COMM_HORIZ_FLIP;
        data_buf[2] = SSD1306_COMM_SCAN_REVS;
    
        ret = i2c_master_send(dev->client, data_buf, 3);
        if (ret < 0) {
            dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
            return ret;
        }
    }
    else if (degree == 180)
    {
        data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
        data_buf[1] = SSD1306_COMM_HORIZ_NORM;
        data_buf[2] = SSD1306_COMM_SCAN_NORM;
    
        ret = i2c_master_send(dev->client, data_buf, 3);
        if (ret < 0) {
            dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
            return ret;
        }
    }
    else 
        return 1;
    
    return 0;
}


uint8_t ssd1306_oled_set_col(struct ssd1306_dev *dev, uint8_t start, uint8_t end)
{
    uint8_t *data_buf = dev->data_buff;
    uint8_t ret = 0;

    data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
    data_buf[1] = SSD1306_COMM_SET_COL_ADDR;
    data_buf[2] = start;
    data_buf[3] = end;
    
    ret = i2c_master_send(dev->client, data_buf, 4);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}

uint8_t ssd1306_oled_set_page(struct ssd1306_dev *dev, uint8_t start, uint8_t end)
{
    uint8_t *data_buf = dev->data_buff;
    uint8_t ret = 0;

    data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
    data_buf[1] = SSD1306_COMM_SET_PAGE_ADDR;
    data_buf[2] = start;
    data_buf[3] = end;
    
    ret = i2c_master_send(dev->client, data_buf, 4);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}


uint8_t ssd1306_oled_horizontal_flip(struct ssd1306_dev *dev, uint8_t flip)
{
    uint8_t *data_buf = dev->data_buff;
    uint8_t ret = 0;

    data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
    if (flip == 0)
        data_buf[1] = SSD1306_COMM_HORIZ_NORM;
    else
        data_buf[1] = SSD1306_COMM_HORIZ_FLIP;
    
    ret = i2c_master_send(dev->client, data_buf, 2);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}

uint8_t ssd1306_oled_display_flip(struct ssd1306_dev *dev, uint8_t flip)
{
    uint8_t *data_buf = dev->data_buff;
    uint8_t ret = 0;

    data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
    if (flip == 0)
        data_buf[1] = SSD1306_COMM_DISP_NORM;
    else
        data_buf[1] = SSD1306_COMM_DISP_INVERSE;
    
    ret = i2c_master_send(dev->client, data_buf, 2);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }
    return 0;
}

uint8_t ssd1306_oled_set_XY(struct ssd1306_dev *dev, uint8_t x, uint8_t y)
{
    int ret = 0;

    if (x >= dev->max_columns || y >= (dev->max_lines / 8))
        return 1;

    dev->x = x;
    dev->y = y;

    uint8_t *data_buf = dev->data_buff;
    
    data_buf[0] = SSD1306_COMM_CONTROL_BYTE;
    data_buf[1] = SSD1306_COMM_PAGE_NUMBER | (y & 0x0f);
    data_buf[2] = SSD1306_COMM_LOW_COLUMN | (x & 0x0f);
    data_buf[3] = SSD1306_COMM_HIGH_COLUMN | ((x >> 4) & 0x0f);

    ret = i2c_master_send(dev->client, data_buf, 4);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}

uint8_t ssd1306_oled_clear_line(struct ssd1306_dev *dev, uint8_t row)
{
    uint8_t i, ret = 0;
    if (row >= (dev->max_lines / 8))
        return 1;

    uint8_t *data_buf = dev->data_buff;
        
    ssd1306_oled_set_XY(dev, 0, row);
    data_buf[0] = SSD1306_DATA_CONTROL_BYTE;
    for (i = 0; i < dev->max_columns; i++)
        data_buf[i+1] = 0x00;

    ret = i2c_master_send(dev->client, data_buf, 1 + dev->max_columns);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}

uint8_t ssd1306_oled_clear_screen(struct ssd1306_dev *dev)
{
    uint8_t rc = 0;
    uint8_t i;

    memset(dev->framebuffer, 0x00, sizeof(dev->framebuffer));
    
    for (i = 0; i < (dev->max_lines / 8); i++)
        rc += ssd1306_oled_clear_line(dev, i);
    
    return rc;
}

uint8_t ssd1306_oled_draw_pixel(struct ssd1306_dev *dev, uint8_t x, uint8_t y, uint8_t on) {
    if (x >= dev->max_columns || y >= dev->max_lines) {
        // Pixel is out of bounds
        return 1;
    }

    uint8_t page = y / 8; // Calculate page number
    uint8_t bit_pos = y % 8;  // Calculate bit position within the byte

    uint16_t index = page * dev->max_columns + x; // Calculate the index in the framebuffer

    if (on) {
        dev->framebuffer[index] |= (1 << bit_pos);   // Set the bit to turn the pixel on
    } else {
        dev->framebuffer[index] &= ~(1 << bit_pos);  // Clear the bit to turn the pixel off
    }

    return 0; // Success
}


uint8_t ssd1306_oled_update_display(struct ssd1306_dev *dev) {
    // Assuming the display is already correctly configured for page addressing mode
    for (uint8_t page = 0; page < (dev->max_lines / 8); ++page) {
        // Set page address
        uint8_t control_bytes[] = {
            SSD1306_COMM_CONTROL_BYTE, 0xB0 | page,    // Set page address
            SSD1306_COMM_CONTROL_BYTE, 0x00,           // Set low column address to 0
            SSD1306_COMM_CONTROL_BYTE, 0x10            // Set high column address to 0
        };
        i2c_master_send(dev->client, control_bytes, sizeof(control_bytes)); 

        // Write the entire page data in one go
        uint8_t *data_start = &dev->framebuffer[page * dev->max_columns];
        uint8_t data[dev->max_columns + 1];
        data[0] = SSD1306_DATA_CONTROL_BYTE;  // Set to data mode
        memcpy(&data[1], data_start, dev->max_columns);  // Copy page data

        i2c_master_send(dev->client, data, sizeof(data)); 
    }
    return 0;
}


uint8_t ssd1306_oled_default_config(struct ssd1306_dev *dev)
{
    int ret, i = 0;

    uint8_t oled_lines = dev->max_lines;
    uint8_t oled_columns = dev->max_columns;

    if (oled_lines != SSD1306_128_64_LINES && oled_lines != SSD1306_128_32_LINES && oled_lines != SSD1306_64_48_LINES)
        oled_lines = SSD1306_128_64_LINES;

    if (oled_columns != SSD1306_128_64_COLUMNS && oled_columns != SSD1306_128_32_COLUMNS && oled_columns != SSD1306_64_48_COLUMNS)
        oled_columns = SSD1306_128_64_COLUMNS;

    uint8_t *data_buf = dev->data_buff;

    // Command sequence
    data_buf[i++] = SSD1306_COMM_CONTROL_BYTE;  //command control byte
    data_buf[i++] = SSD1306_COMM_DISPLAY_OFF;   //display off
    data_buf[i++] = SSD1306_COMM_DISP_NORM;     //Set Normal Display (default)
    data_buf[i++] = SSD1306_COMM_CLK_SET;       //SETDISPLAYCLOCKDIV
    data_buf[i++] = 0x80;                       // the suggested ratio 0x80
    data_buf[i++] = SSD1306_COMM_MULTIPLEX;     //SSD1306_SETMULTIPLEX
    data_buf[i++] = oled_lines - 1;             // height is 32 or 64 (always -1)
    data_buf[i++] = SSD1306_COMM_VERT_OFFSET;   //SETDISPLAYOFFSET
    data_buf[i++] = 0;                          //no offset
    data_buf[i++] = SSD1306_COMM_START_LINE;    //SETSTARTLINE
    data_buf[i++] = SSD1306_COMM_CHARGE_PUMP;   //CHARGEPUMP
    data_buf[i++] = 0x14;                       //turn on charge pump
    data_buf[i++] = SSD1306_COMM_MEMORY_MODE;   //MEMORYMODE
    data_buf[i++] = SSD1306_PAGE_MODE;          // page mode
    data_buf[i++] = SSD1306_COMM_HORIZ_NORM;    //SEGREMAP  Mirror screen horizontally (A0)
    data_buf[i++] = SSD1306_COMM_SCAN_NORM;     //COMSCANDEC Rotate screen vertically (C0)
    data_buf[i++] = SSD1306_COMM_COM_PIN;       //HARDWARE PIN 
    if (oled_lines == 32)
        data_buf[i++] = 0x02;                       // for 32 lines
    else
        data_buf[i++] = 0x12;                       // for 64 lines or 48 lines
    data_buf[i++] = SSD1306_COMM_CONTRAST;      //SETCONTRAST
    data_buf[i++] = 0x7f;                       // default contract value
    data_buf[i++] = SSD1306_COMM_PRECHARGE;     //SETPRECHARGE
    data_buf[i++] = 0xf1;                       // default precharge value
    data_buf[i++] = SSD1306_COMM_DESELECT_LV;   //SETVCOMDETECT                
    data_buf[i++] = 0x40;                       // default deselect value
    data_buf[i++] = SSD1306_COMM_RESUME_RAM;    //DISPLAYALLON_RESUME
    data_buf[i++] = SSD1306_COMM_DISP_NORM;     //NORMALDISPLAY
    data_buf[i++] = SSD1306_COMM_DISPLAY_ON;    //DISPLAY ON             
    data_buf[i++] = SSD1306_COMM_DISABLE_SCROLL;//Stop scroll

    // Sending the command sequence to the SSD1306
    ret = i2c_master_send(dev->client, data_buf, i);
    if (ret < 0) {
        dev_err(&dev->client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}

void ssd1306_oled_draw_area(struct ssd1306_dev *dev, const uint8_t *data, int width, int height, int start_x, int start_y) {
    // pr_info("Starting to draw area...\n");
    // Ensure the starting point and image dimensions do not exceed the display boundaries
    // Adjust start_x and start_y if they are out of bounds to prevent buffer underflow
    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;

    for (int y = 0; y < height; y++) {
        int current_y = start_y + y; // Calculate the current y position on the display
        if (current_y >= dev->max_lines) break; // Stop if the y position is beyond the display height

        for (int x = 0; x < width; x++) {
            int current_x = start_x + x; // Calculate the current x position on the display
            if (current_x >= dev->max_columns) break; // Stop if the x position is beyond the display width

            // Calculate the index in the image data
            int index = (y * ((width + 7) / 8)) + x / 8;
            // Determine if the pixel should be on or off
            uint8_t on = (data[index] >> (7 - (x % 8))) & 1;
            // Draw the pixel at the calculated position on the display
            ssd1306_oled_draw_pixel(dev, current_x, current_y, on);
        }
    }

    // Update the display after drawing is complete
    ssd1306_oled_update_display(dev);
    // pr_info("Area drawing complete.\n");
}


void ssd1306_oled_test_image(struct ssd1306_dev *dev) {
    ssd1306_oled_draw_area(dev, demo_image_data, demo_image_width, demo_image_height, 0, 0);
}


///////////////// Implement File Operations //////////////////////////

static int ssd1306_open(struct inode *inode, struct file *file) {
    struct ssd1306_char_dev *dev;

    dev = container_of(inode->i_cdev, struct ssd1306_char_dev, cdev);
    file->private_data = dev; // Store a pointer to the device structure for other operations

    printk(KERN_INFO "SSD1306 device opened\n");
    return 0;
}

static ssize_t ssd1306_write(struct file *file, const char __user *buffer, size_t len, loff_t *offset) {
    // printk(KERN_INFO "SSD1306 device write request\n");
    
    struct ssd1306_char_dev *dev = file->private_data;

    // Ensure 'dev' and other critical pointers are not NULL.
    if (!dev || !dev->ssd1306.client) {
        printk(KERN_ERR "SSD1306: Device structure or critical component uninitialized\n");
        return -EFAULT;
    }

    ssd1306_data_packet_u packet;

    if(len > MAX_COMMAND_SIZE || copy_from_user((uint8_t*)packet.raw, buffer, len)) {
        return -EFAULT;
    }

    // printk(KERN_INFO "SSD1306 received command = [%d]\n", packet.data.command);

    // Parse command
    switch (packet.data.command)
    {
    case SSD1306_CMD_SET_ROTATE:
    {
        ssd1306_oled_set_rotate(&dev->ssd1306, packet.data.payload.rotate.angle);
    }
    break;
    case SSD1306_CMD_HORIZONTAL_FLIP:
    {
        ssd1306_oled_horizontal_flip(&dev->ssd1306, packet.data.payload.horizontal_flip.state);
    }
    break;
    case SSD1306_CMD_DISPLAY_FLIP:
    {
        ssd1306_oled_display_flip(&dev->ssd1306, packet.data.payload.display_flip.state);
    }
    break;

    case SSD1306_CMD_CLEAR_SCREEN:
    {
        ssd1306_oled_clear_screen(&dev->ssd1306);
    }
    break;
    case SSD1306_CMD_DRAW_PIXEL:
    {
        uint8_t x = packet.data.payload.draw_pixel.x;
        uint8_t y = packet.data.payload.draw_pixel.y;
        uint8_t state = packet.data.payload.draw_pixel.state; // on, off

        ssd1306_oled_draw_pixel(&dev->ssd1306, x, y, state);
        ssd1306_oled_update_display(&dev->ssd1306);
    }
    break;

    case SSD1306_CMD_DRAW_AREA:
    {
        uint8_t x = packet.data.payload.draw_area.x;
        uint8_t y = packet.data.payload.draw_area.y;
        uint8_t width = packet.data.payload.draw_area.width;
        uint8_t heigh = packet.data.payload.draw_area.height;
        uint8_t *demo_image_data = packet.data.payload.draw_area.data;

        if (width == 0 || heigh == 0) {
            printk(KERN_INFO "SSD1306 invalid width or heigh\n");
        }
        else {
            ssd1306_oled_draw_area(&dev->ssd1306, demo_image_data, width, heigh, x, y);
        }
    }
    break;

    default:
        printk(KERN_WARNING "SSD1306 Unsupported command\n");
        return -EINVAL;
    }

    return len;
}

static struct file_operations ssd1306_fops = {
    .owner = THIS_MODULE,
    .open = ssd1306_open,
    .write = ssd1306_write,
    // other operations...
};

/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

// Probe function called when a matching I2C device is found
static int ssd1306_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    int err;
    // you generally do not need to explicitly free memory allocated with devm_kzalloc()
    struct ssd1306_char_dev *dev = devm_kzalloc(&client->dev, sizeof(struct ssd1306_char_dev), GFP_KERNEL);
    if (!dev)
        return -ENOMEM;

    dev->ssd1306.client = client;
    printk(KERN_INFO "SSD1306: OLED device found at addr 0x%x\n", client->addr);


    // Initialize the cdev structure and add it to the kernel
    // struct cdev *ssd1306_cdev = cdev_alloc();
    cdev_init(&dev->cdev, &ssd1306_fops); // Initialize cdev in your device structure
    dev->cdev.owner = THIS_MODULE;

    err = cdev_add(&dev->cdev, dev_num, 1);
    if (err) {
        printk(KERN_ERR "cdev_add failed\n");
        class_destroy(ssd1306_class);
        unregister_chrdev_region(dev_num, 1);
        return err;
    }

    uint32_t oled_lines, oled_columns;
    // Attempt to read the display resolution from the device tree
    if (device_property_read_u32(&client->dev, "oled-lines", &oled_lines))
        oled_lines = SSD1306_128_64_LINES; // Default value if property is not found

    if (device_property_read_u32(&client->dev, "oled-columns", &oled_columns))
        oled_columns = SSD1306_128_64_COLUMNS; // Default value if property is not found

    printk(KERN_INFO "SSD1306: Display resolution set to %ux%u\n", oled_columns, oled_lines);

    dev->ssd1306.max_columns = oled_columns;
    dev->ssd1306.max_lines = oled_lines;
    dev->ssd1306.x = 0;
    dev->ssd1306.y = 0;

    // Store the device structure pointer for later retrieval
    i2c_set_clientdata(client, dev);

   // After successfully setting up cdev and allocating major/minor numbers
    ssd1306_device = device_create(ssd1306_class, NULL, MKDEV(major_number, 0), NULL, "ssd1306");
    if (IS_ERR(ssd1306_device)) {
        printk(KERN_ALERT "Failed to create the device\n");
        // Cleanup previously allocated resources
        class_destroy(ssd1306_class);
        unregister_chrdev_region(MKDEV(major_number, 0), 1);
        // Handle other cleanups as necessary
        return PTR_ERR(ssd1306_device);
    }

    // Inside ssd1306_probe after reading properties
    if (ssd1306_oled_default_config(&dev->ssd1306)) {
        printk(KERN_ERR "SSD1306: Failed to initialize OLED with specified resolution\n");
        return -EIO;
    }

    // clear screen 
    printk(KERN_INFO "SSD1306: Clear Screen \n");
    ssd1306_oled_clear_screen(&dev->ssd1306);

    #if 0
    printk(KERN_INFO "SSD1306: Testing pattern\n");
    ssd1306_oled_test_image(&dev->ssd1306);
    #endif

    return 0;
}

// Remove function called when the I2C device is removed
static void ssd1306_remove(struct i2c_client *client)
{
    printk(KERN_INFO "SSD1306: OLED device removed\n");

    struct ssd1306_char_dev *dev = i2c_get_clientdata(client);

    // Cleanup character device
    cdev_del(&dev->cdev);


    printk(KERN_INFO "SSD1306: OLED device removed\n");
}

// I2C device ID table
static const struct i2c_device_id ssd1306_id[] = {
    { "ssd1306", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, ssd1306_id);

// I2C driver structure
static struct i2c_driver ssd1306_driver = {
    .driver = {
        .name = "ssd1306",
        .owner = THIS_MODULE,
    },
    .probe = ssd1306_probe,
    .remove = ssd1306_remove,
    .id_table = ssd1306_id,
};



// Module initialization function
static int __init ssd1306_init(void)
{
    printk(KERN_INFO "SSD1306: Initializing the SSD1306 OLED driver\n");

    int err;

    // Allocate a major number
    err = alloc_chrdev_region(&dev_num, 0, 1, "ssd1306");
    if (err < 0) {
        printk(KERN_WARNING "SSD1306: Can't allocate device number\n");
        return err;
    }
    major_number = MAJOR(dev_num);

    // Create a device class 
    ssd1306_class = class_create(THIS_MODULE, "ssd1306");
    if(IS_ERR(ssd1306_class))
    {
        unregister_chrdev_region(MKDEV(major_number, 0), 1);
        return -1;
    }

    return i2c_add_driver(&ssd1306_driver);
}

// Module exit function
static void __exit ssd1306_exit(void)
{
    printk(KERN_INFO "SSD1306: Exiting the SSD1306 OLED driver\n");

    // If you have registered a device class and created a device, remove them as well
    device_destroy(ssd1306_class, MKDEV(major_number, 0));
    class_destroy(ssd1306_class);

    // Cleanup device number
    unregister_chrdev_region(MKDEV(major_number, 0), 1);

    i2c_del_driver(&ssd1306_driver);
}





module_init(ssd1306_init);
module_exit(ssd1306_exit);