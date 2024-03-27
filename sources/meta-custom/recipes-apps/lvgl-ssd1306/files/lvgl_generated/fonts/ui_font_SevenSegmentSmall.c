/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font /home/bayron/SquareLine/assets/Seven Segment.ttf -o /home/bayron/SquareLine/assets/ui_font_SevenSegmentSmall.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_SEVENSEGMENTSMALL
#define UI_FONT_SEVENSEGMENTSMALL 1
#endif

#if UI_FONT_SEVENSEGMENTSMALL

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xe0,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x14, 0x2b, 0xf9, 0x4f, 0xea, 0x14, 0x0,

    /* U+0024 "$" */
    0x10, 0xfa, 0x4, 0x8, 0x10, 0x1f, 0x1, 0x2,
    0x4, 0xb, 0xe1, 0x0,

    /* U+0025 "%" */
    0x0, 0x0, 0x46, 0x32, 0x48, 0x94, 0x19, 0x0,
    0x98, 0x29, 0x12, 0x4c, 0x62, 0x0, 0x80,

    /* U+0026 "&" */
    0x78, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0,
    0x0, 0x80, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0,
    0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0x7, 0x8f,
    0x8f, 0x1e, 0xf, 0x81, 0x1, 0x2, 0x11, 0x8,
    0x10, 0x10, 0x21, 0x10, 0x81, 0x1, 0x2, 0x11,
    0x8, 0x10, 0x10, 0x21, 0x10, 0x79, 0x1, 0x1,
    0xe1, 0x0,

    /* U+0028 "(" */
    0x78, 0x88, 0x80, 0x88, 0x88, 0x70,

    /* U+0029 ")" */
    0xe1, 0x11, 0x10, 0x11, 0x11, 0xe0,

    /* U+002A "*" */
    0x27, 0xdd, 0xf2, 0x0,

    /* U+002B "+" */
    0x8, 0x4, 0x2, 0x1, 0xf, 0x78, 0x40, 0x20,
    0x10, 0x8, 0x0,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x2, 0x8, 0x10, 0x41, 0x80, 0x8, 0x10, 0x41,
    0x82, 0x0,

    /* U+0030 "0" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0031 "1" */
    0xfb, 0xe0,

    /* U+0032 "2" */
    0x78, 0x10, 0x41, 0x5, 0xe8, 0x20, 0x82, 0x7,
    0x80,

    /* U+0033 "3" */
    0xf0, 0x42, 0x10, 0xf8, 0x21, 0x8, 0x7c,

    /* U+0034 "4" */
    0x86, 0x18, 0x61, 0x85, 0xe0, 0x41, 0x4, 0x10,
    0x40,

    /* U+0035 "5" */
    0x7a, 0x8, 0x20, 0x81, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+0036 "6" */
    0x7a, 0x8, 0x20, 0x81, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0037 "7" */
    0xf0, 0x42, 0x10, 0x80, 0x21, 0x8, 0x42,

    /* U+0038 "8" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0039 "9" */
    0x7a, 0x18, 0x61, 0x85, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+003A ":" */
    0xd8,

    /* U+003C "<" */
    0x29, 0x68, 0x26, 0x48, 0x80,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x91, 0x22, 0x1a, 0x52, 0x0,

    /* U+003F "?" */
    0x78, 0x10, 0x41, 0x5, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0040 "@" */
    0x7a, 0x18, 0x67, 0xa6, 0x9a, 0x69, 0x9a, 0x7,
    0x80,

    /* U+0041 "A" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0042 "B" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0043 "C" */
    0x7c, 0x21, 0x8, 0x2, 0x10, 0x84, 0x1e,

    /* U+0044 "D" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0045 "E" */
    0x7c, 0x21, 0x8, 0x3e, 0x10, 0x84, 0x1e,

    /* U+0046 "F" */
    0x7c, 0x21, 0x8, 0x3e, 0x10, 0x84, 0x20,

    /* U+0047 "G" */
    0x7a, 0x8, 0x20, 0x80, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0049 "I" */
    0xfb, 0xe0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+004B "K" */
    0x86, 0x29, 0x28, 0xc1, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x2, 0x10, 0x84, 0x1e,

    /* U+004D "M" */
    0x77, 0x44, 0x62, 0x31, 0x18, 0x88, 0x2, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x20,

    /* U+004E "N" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x18,
    0x40,

    /* U+004F "O" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0050 "P" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0051 "Q" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x27,
    0xc0,

    /* U+0052 "R" */
    0x7a, 0x18, 0x61, 0x85, 0xec, 0x28, 0x92, 0x28,
    0x40,

    /* U+0053 "S" */
    0x7a, 0x8, 0x20, 0x81, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+0054 "T" */
    0xee, 0x20, 0x40, 0x81, 0x0, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0056 "V" */
    0x86, 0x18, 0x61, 0x84, 0x8, 0x73, 0x49, 0x23,
    0x0,

    /* U+0057 "W" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0x8, 0x2, 0x23,
    0x11, 0x88, 0xc4, 0x5d, 0xc0,

    /* U+0058 "X" */
    0x86, 0x14, 0x92, 0x38, 0x7, 0x92, 0x4a, 0x18,
    0x40,

    /* U+0059 "Y" */
    0x86, 0x18, 0x61, 0x85, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+005A "Z" */
    0xf8, 0x10, 0x82, 0x10, 0x2, 0x10, 0x42, 0x7,
    0xc0,

    /* U+005B "[" */
    0x78, 0x88, 0x80, 0x88, 0x88, 0x70,

    /* U+005C "\\" */
    0x81, 0x81, 0x1, 0x2, 0x0, 0x4, 0x4, 0xc,
    0x8, 0x8,

    /* U+005D "]" */
    0xe1, 0x11, 0x10, 0x11, 0x11, 0xe0,

    /* U+005E "^" */
    0x3b, 0x9c, 0x1c,

    /* U+005F "_" */
    0xff,

    /* U+0061 "a" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0062 "b" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0063 "c" */
    0x7c, 0x21, 0x8, 0x2, 0x10, 0x84, 0x1e,

    /* U+0064 "d" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0065 "e" */
    0x7c, 0x21, 0x8, 0x3e, 0x10, 0x84, 0x1e,

    /* U+0066 "f" */
    0x7c, 0x21, 0x8, 0x3e, 0x10, 0x84, 0x20,

    /* U+0067 "g" */
    0x7a, 0x8, 0x20, 0x80, 0xe8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0068 "h" */
    0x86, 0x18, 0x61, 0x85, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+0069 "i" */
    0xfb, 0xe0,

    /* U+006A "j" */
    0x4, 0x10, 0x41, 0x4, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+006B "k" */
    0x86, 0x29, 0x28, 0xc1, 0xe8, 0x61, 0x86, 0x18,
    0x40,

    /* U+006C "l" */
    0x84, 0x21, 0x8, 0x2, 0x10, 0x84, 0x1e,

    /* U+006D "m" */
    0x77, 0x44, 0x62, 0x31, 0x18, 0x88, 0x2, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x20,

    /* U+006E "n" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x18,
    0x40,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0070 "p" */
    0x7a, 0x18, 0x61, 0x85, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x7a, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x27,
    0xc0,

    /* U+0072 "r" */
    0x7a, 0x18, 0x61, 0x85, 0xec, 0x28, 0x92, 0x28,
    0x40,

    /* U+0073 "s" */
    0x7a, 0x8, 0x20, 0x81, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+0074 "t" */
    0xee, 0x20, 0x40, 0x81, 0x0, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x84, 0x8, 0x61, 0x86, 0x17,
    0x80,

    /* U+0076 "v" */
    0x86, 0x18, 0x61, 0x84, 0x8, 0x73, 0x49, 0x23,
    0x0,

    /* U+0077 "w" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0x8, 0x2, 0x23,
    0x11, 0x88, 0xc4, 0x5d, 0xc0,

    /* U+0078 "x" */
    0x86, 0x14, 0x92, 0x38, 0x7, 0x92, 0x4a, 0x18,
    0x40,

    /* U+0079 "y" */
    0x86, 0x18, 0x61, 0x85, 0xe0, 0x41, 0x4, 0x17,
    0x80,

    /* U+007A "z" */
    0xf8, 0x10, 0x82, 0x10, 0x2, 0x10, 0x42, 0x7,
    0xc0,

    /* U+007B "{" */
    0x1c, 0x82, 0x8, 0x23, 0x2, 0x8, 0x20, 0x81,
    0xc0,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xe0, 0x41, 0x4, 0x10, 0x31, 0x4, 0x10, 0x4e,
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 77, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 47, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 72, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 4, .adv_w = 140, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 129, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 23, .adv_w = 180, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 38, .adv_w = 605, .box_w = 36, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 106, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 104, .adv_w = 169, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 115, .adv_w = 59, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 104, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 117, .adv_w = 47, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 47, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 47, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 74, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 141, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 217, .adv_w = 74, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 47, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 210, .box_w = 11, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 493, .adv_w = 160, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 47, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 116, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 129, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 722, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 47, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 733, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 7, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 40, .range_length = 19, .glyph_id_start = 8,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 60, .range_length = 36, .glyph_id_start = 27,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 29, .glyph_id_start = 63,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_SevenSegmentSmall = {
#else
lv_font_t ui_font_SevenSegmentSmall = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_SEVENSEGMENTSMALL*/

