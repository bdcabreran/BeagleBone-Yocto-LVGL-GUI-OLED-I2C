#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bayron Cabrera");
MODULE_DESCRIPTION("A simple Linux Driver for SSD1306 OLED.");
MODULE_VERSION("0.1");

// Device specific structure
struct ssd1306_dev {
    struct i2c_client *client;
    // Add other parameters like buffer for screen data if necessary
};

// Probe function called when a matching I2C device is found
static int ssd1306_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    printk(KERN_INFO "SSD1306: OLED device found at addr 0x%x\n", client->addr);
    // Device initialization code here
    // For example, sending initialization commands to the OLED display

    return 0;
}

// Remove function called when the I2C device is removed
static int ssd1306_remove(struct i2c_client *client)
{
    printk(KERN_INFO "SSD1306: OLED device removed\n");
    // Cleanup code here, if necessary

    return 0;
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
