// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SSD1306_LVGL

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
lv_obj_t * ui_MainScreen;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_clockImg;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_WetherImg;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_MusicImg;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label1;


// SCREEN: ui_ClockScreen
void ui_ClockScreen_screen_init(void);
lv_obj_t * ui_ClockScreen;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_hour;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_minute;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_second;
lv_obj_t * ui_Panel7;
lv_obj_t * ui_date;


// SCREEN: ui_GraphScreen
void ui_GraphScreen_screen_init(void);
lv_obj_t * ui_GraphScreen;
lv_obj_t * ui_Chart1;


// SCREEN: ui_MusicScreen
void ui_MusicScreen_screen_init(void);
lv_obj_t * ui_MusicScreen;
lv_obj_t * ui_Label8;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Image6;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 8
    #error "LV_COLOR_DEPTH should be 8bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    ui_ClockScreen_screen_init();
    ui_GraphScreen_screen_init();
    ui_MusicScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_MainScreen);
}