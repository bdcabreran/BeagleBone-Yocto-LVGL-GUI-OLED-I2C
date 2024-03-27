#ifndef SSD1306_H
#define SSD1306_H

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#define SSD1306_128_64_LINES        64
#define SSD1306_128_32_LINES        32
#define SSD1306_64_48_LINES         48

#define SSD1306_128_64_COLUMNS      128
#define SSD1306_128_32_COLUMNS      128
#define SSD1306_64_48_COLUMNS       64

void ssd1306_init(void);
void ssd1306_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map);

#endif
