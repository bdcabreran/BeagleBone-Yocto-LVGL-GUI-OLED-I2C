#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include "ssd1306.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bayron Cabrera");
MODULE_DESCRIPTION("A simple Linux Driver for SSD1306 OLED.");
MODULE_VERSION("0.1");

// Device specific structure
struct ssd1306_dev {
    struct i2c_client *client;
    // Add other parameters like buffer for screen data if necessary
};

////////////////////////////////////////////////////////////////////////////////

uint8_t ssd1306_oled_default_config(struct i2c_client *client, uint8_t oled_lines, uint8_t oled_columns)
{
    uint8_t data_buf[64]; // Adjust the size based on the maximum commands sent
    int ret, i = 0;

    if (oled_lines != SSD1306_128_64_LINES && oled_lines != SSD1306_128_32_LINES && oled_lines != SSD1306_64_48_LINES)
        oled_lines = SSD1306_128_64_LINES;

    if (oled_columns != SSD1306_128_64_COLUMNS && oled_columns != SSD1306_128_32_COLUMNS && oled_columns != SSD1306_64_48_COLUMNS)
        oled_columns = SSD1306_128_64_COLUMNS;


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
    ret = i2c_master_send(client, data_buf, i);
    if (ret < 0) {
        dev_err(&client->dev, "Failed to write initial config to SSD1306, error: %d\n", ret);
        return ret;
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////

// Probe function called when a matching I2C device is found
static int ssd1306_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    printk(KERN_INFO "SSD1306: OLED device found at addr 0x%x\n", client->addr);

    uint32_t oled_lines, oled_columns;
    // Attempt to read the display resolution from the device tree
    if (device_property_read_u32(&client->dev, "oled-lines", &oled_lines))
        oled_lines = SSD1306_128_64_LINES; // Default value if property is not found

    if (device_property_read_u32(&client->dev, "oled-columns", &oled_columns))
        oled_columns = SSD1306_128_64_COLUMNS; // Default value if property is not found

    printk(KERN_INFO "SSD1306: Display resolution set to %ux%u\n", oled_columns, oled_lines);

    // Inside ssd1306_probe after reading properties
    if (ssd1306_oled_default_config(client, oled_lines, oled_columns)) {
        printk(KERN_ERR "SSD1306: Failed to initialize OLED with specified resolution\n");
        return -EIO;
    }

    return 0;
}

// Remove function called when the I2C device is removed
static void ssd1306_remove(struct i2c_client *client)
{
    printk(KERN_INFO "SSD1306: OLED device removed\n");
    // Cleanup code here, if necessary
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
    return i2c_add_driver(&ssd1306_driver);
}

// Module exit function
static void __exit ssd1306_exit(void)
{
    printk(KERN_INFO "SSD1306: Exiting the SSD1306 OLED driver\n");
    i2c_del_driver(&ssd1306_driver);
}

module_init(ssd1306_init);
module_exit(ssd1306_exit);
