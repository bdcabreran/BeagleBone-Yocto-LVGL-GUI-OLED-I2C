
# SSD1306 Driver for LVGL

This driver enables the SSD1306 OLED display to be used with the LVGL embedded graphics library, facilitating the creation of GUIs on small screens. It has been designed for ease of integration within the `lv_drivers/display` directory of LVGL.

## Features

- Drawing of pixels, lines, areas, and GIFs on the SSD1306 display.
- Support for rotating the display and flipping it horizontally or vertically.
- Efficient conversion of LVGL colors to the SSD1306's monochrome color space.
- Simple API for initializing the display, flushing graphics, and handling screen updates.

## Prerequisites

Before you begin, ensure you have the following:

- A development environment for your embedded system.
- The LVGL library configured in your project.
- Access to the SSD1306 display through your embedded system's GPIO or I²C/SPI bus.

## Installation

1. **Include the SSD1306 driver** in your project by adding `#include "SSD1306.h"` to your main application file or wherever you initialize the LVGL library. you might want to place it on the `lv_drivers/display` folder in case you are using `lv_drivers`

## Usage

1. **Initialize the display** by calling `ssd1306_init()` before initializing LVGL. This step is crucial to prepare the SSD1306 display for communication.

2. **Configure LVGL to use the SSD1306 driver** by setting up a display driver in LVGL and registering the SSD1306 flush callback:

```c
lv_disp_drv_t disp_drv;
lv_disp_drv_init(&disp_drv);
disp_drv.flush_cb = ssd1306_flush;
disp_drv.hor_res = 128;
disp_drv.ver_res = 64;
lv_disp_drv_register(&disp_drv);
```

3. **Use LVGL's API** to create your GUI. The SSD1306 driver handles the rendering of LVGL objects onto the OLED display.

## API Reference

The driver exposes several functions for advanced control over the SSD1306 display. Here are some key functions:

- `void ssd1306_init(void)`: Initializes the SSD1306 display.
- `void ssd1306_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)`: Flushes the LVGL drawing area to the SSD1306 display.

Refer to `SSD1306.h` for the complete API.

## License

This SSD1306 driver is licensed under [MIT License](LICENSE). 

## Acknowledgements

Thanks to the LVGL community for providing an extensive and flexible graphics library suitable for embedded applications.
```
