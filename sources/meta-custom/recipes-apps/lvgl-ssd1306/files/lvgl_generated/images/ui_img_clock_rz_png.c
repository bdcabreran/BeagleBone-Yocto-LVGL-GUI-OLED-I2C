// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SSD1306_LVGL

#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

// IMAGE DATA: assets/clock_rz.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_clock_rz_png_data[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x00,0x4E,0x00,0x8E,0x00,0xC1,0x00,0xE2,0x00,0xFC,0x00,0xFF,0x00,0xFC,0x00,0xE2,0x00,0xC2,0x00,0x8E,0x00,0x4E,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0x9E,0x00,0xF3,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF4,0x00,0x9E,0x00,0x2D,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0xA6,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xEE,0x00,0xAB,0x00,0x72,0x00,0x4B,0x00,0x33,0x00,0x34,0x00,0x33,0x00,0x4B,0x00,0x72,0x00,0xAB,0x00,0xEE,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xA6,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x00,0xF0,0x00,0xFF,0x00,0xFF,0x00,0xC1,0x00,0x50,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x4F,0x00,0xC1,0x00,0xFF,0x00,0xFF,0x00,0xF1,0x00,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x8D,0x00,0xFF,0x00,0xFF,0x00,0xD9,0x00,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x91,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x00,0xD8,0x00,0xFF,0x00,0xFF,0x00,0x8E,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x9C,0x00,0xFF,
    0x00,0xFF,0x00,0x9A,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x95,0x00,0xFF,0x00,0x95,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0x9A,0x00,0xFF,0x00,0xFF,0x00,0x9D,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8E,0x00,0xFF,0x00,0xFF,0x00,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0x00,0xFF,0x00,0xFF,0x00,0x8D,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x00,0xFF,0x00,0xFF,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0x00,0xFF,0x00,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0x00,0xFF,0x00,0xFF,0x00,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0xF1,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x5C,0x00,0xBC,0x00,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0xB5,0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0xBC,0x00,0x5C,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0xF0,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA6,0x00,0xFF,0x00,0xD9,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0xBC,0x00,0xFF,0x00,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x56,0x00,0xFF,0x00,0xBC,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0xD9,0x00,0xFF,0x00,0xA6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0xFF,0x00,0xFF,0x00,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0x56,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x56,0x00,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0xFF,0x00,0xFF,0x00,0x2C,0x00,0x00,0x00,0x00,0x00,0x9E,0x00,0xFF,0x00,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x68,0x00,0xFF,0x00,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x00,0xFF,0x00,0x9E,0x00,0x00,0x00,0x0A,0x00,0xF4,0x00,0xFF,0x00,0x50,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0xFF,0x00,0xF3,0x00,0x0A,0x00,0x4E,0x00,0xFF,0x00,0xEE,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x04,0x00,0xEE,0x00,0xFF,0x00,0x4E,0x00,0x8E,0x00,0xFF,0x00,0xAB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAB,0x00,0xFF,0x00,0x8E,0x00,0xC2,0x00,0xFF,0x00,0x72,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x72,0x00,0xFF,0x00,0xC2,0x00,0xE2,0x00,0xFF,0x00,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0xFF,0x00,0xE2,0x00,0xFC,0x00,0xFF,0x00,0x33,0x00,0x00,0x00,0x20,0x00,0x95,0x00,0x9A,0x00,0x98,0x00,0x36,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x98,0x00,0x9A,0x00,0x95,0x00,0x20,0x00,0x00,0x00,0x33,0x00,0xFF,0x00,0xFC,0x00,0xFF,0x00,0xFF,0x00,0x34,0x00,0x00,0x00,0x91,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xB5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x94,0x00,0xFF,0x00,0xE2,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB5,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x91,0x00,0x00,0x00,0x34,0x00,0xFF,0x00,0xFF,0x00,0xFC,
    0x00,0xFF,0x00,0x33,0x00,0x00,0x00,0x20,0x00,0x95,0x00,0x9A,0x00,0x98,0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x00,0xE2,0x00,0xFF,0x00,0xE2,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x98,0x00,0x9A,0x00,0x95,0x00,0x20,0x00,0x00,0x00,0x33,0x00,0xFF,0x00,0xFC,0x00,0xE2,0x00,0xFF,0x00,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0xE2,0x00,0xFF,0x00,0xE3,0x00,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0xFF,0x00,0xE2,0x00,0xC2,0x00,0xFF,0x00,0x72,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x00,0xE3,0x00,0xFF,0x00,0xE3,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x73,0x00,0xFF,0x00,0xC2,0x00,0x8E,0x00,0xFF,0x00,0xAB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x21,0x00,0xE3,0x00,0xFF,0x00,0xE3,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAB,0x00,0xFF,0x00,0x8D,0x00,0x4E,0x00,0xFF,0x00,0xEE,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x00,0xE2,0x00,0xFF,0x00,0xE2,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0xEE,0x00,0xFF,0x00,0x4E,0x00,0x0A,0x00,0xF3,0x00,0xFF,0x00,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0xE2,0x00,0xFF,0x00,0xE1,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0xFF,0x00,0xF3,0x00,0x0A,0x00,0x00,0x00,0x9E,0x00,0xFF,0x00,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0xE1,0x00,0xE1,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x00,0xFF,
    0x00,0x9D,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0xFF,0x00,0xFF,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0x56,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,0x01,0x00,0x56,0x00,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0xFF,0x00,0xFF,0x00,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA6,0x00,0xFF,0x00,0xD9,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0xBC,0x00,0xFF,0x00,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x56,0x00,0xFF,0x00,0xBC,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0xD9,0x00,0xFF,0x00,0xA5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0xF0,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x5B,0x00,0xBC,0x00,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0xB5,0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0xBC,0x00,0x5C,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0xF0,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x00,0xFF,0x00,0xFF,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x98,0x00,0xFF,0x00,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0x00,0xFF,0x00,0xFF,0x00,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8D,0x00,0xFF,0x00,0xFF,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9A,0x00,0xFF,0x00,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0x00,0xFF,0x00,0xFF,0x00,0x8D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
    0x00,0x9C,0x00,0xFF,0x00,0xFF,0x00,0x9A,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x95,0x00,0xFF,0x00,0x95,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0x9A,0x00,0xFF,0x00,0xFF,0x00,0x9D,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x8D,0x00,0xFF,0x00,0xFF,0x00,0xD9,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x91,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0xD9,0x00,0xFF,0x00,0xFF,0x00,0x8D,0x00,0x01,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x57,0x00,0xF0,0x00,0xFF,0x00,0xFF,0x00,0xC2,0x00,0x50,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x50,0x00,0xC1,0x00,0xFF,0x00,0xFF,0x00,0xF1,0x00,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0xA6,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xEE,0x00,0xAB,0x00,0x72,0x00,0x4B,0x00,0x33,0x00,0x34,0x00,0x33,0x00,0x4B,0x00,0x72,
    0x00,0xAB,0x00,0xEE,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xA5,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2C,0x00,0x9D,0x00,0xF3,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xF3,0x00,0x9E,0x00,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x09,0x00,0x4E,0x00,0x8D,0x00,0xC1,0x00,0xE2,0x00,0xFC,0x00,0xFF,0x00,0xFC,0x00,0xE2,0x00,0xC2,0x00,0x8E,0x00,0x4E,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
const lv_img_dsc_t ui_img_clock_rz_png = {
    .header.always_zero = 0,
    .header.w = 37,
    .header.h = 37,
    .data_size = sizeof(ui_img_clock_rz_png_data),
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = ui_img_clock_rz_png_data
};
