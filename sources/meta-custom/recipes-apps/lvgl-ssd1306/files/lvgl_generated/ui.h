// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SSD1306_LVGL

#ifndef _SSD1306_LVGL_UI_H
#define _SSD1306_LVGL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_clockImg;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_WetherImg;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_MusicImg;
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label1;
// SCREEN: ui_ClockScreen
void ui_ClockScreen_screen_init(void);
extern lv_obj_t * ui_ClockScreen;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_hour;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_minute;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_second;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_date;
// SCREEN: ui_GraphScreen
void ui_GraphScreen_screen_init(void);
extern lv_obj_t * ui_GraphScreen;
extern lv_obj_t * ui_Chart1;
// SCREEN: ui_MusicScreen
void ui_MusicScreen_screen_init(void);
extern lv_obj_t * ui_MusicScreen;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_Bar1;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_clock_rz_png);    // assets/clock_rz.png
LV_IMG_DECLARE(ui_img_bar_chart_rz_png);    // assets/bar_chart_rz.png
LV_IMG_DECLARE(ui_img_1888242194);    // assets/music-note_rz.png
LV_IMG_DECLARE(ui_img_pause_rz_png);    // assets/pause_rz.png
LV_IMG_DECLARE(ui_img_backward_rz_png);    // assets/backward_rz.png


LV_FONT_DECLARE(ui_font_CounterStream);
LV_FONT_DECLARE(ui_font_SevenSegment);
LV_FONT_DECLARE(ui_font_SevenSegmentSmall);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
