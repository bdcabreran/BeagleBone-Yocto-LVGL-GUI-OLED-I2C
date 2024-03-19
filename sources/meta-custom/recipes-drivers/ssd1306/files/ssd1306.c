#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bayron Cabrera");
MODULE_DESCRIPTION("A simple Linux Driver for SSD1206 OLED.");
MODULE_VERSION("0.1");

static int __init ssd1306_init(void)
{
    printk(KERN_INFO "SSD1306: Initializing the SSD1306 OLED driver\n");

    return 0;
}

static void __exit ssd1306_exit(void)
{
    printk(KERN_INFO "SSD1306: Exiting the SSD1306 OLED driver\n");
}

module_init(ssd1306_init);
module_exit(ssd1306_exit);

