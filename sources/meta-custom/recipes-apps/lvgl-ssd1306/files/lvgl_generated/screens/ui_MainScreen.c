// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SSD1306_LVGL

#include "../ui.h"

void ui_MainScreen_screen_init(void)
{
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_MainScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MainScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel1, 41);
    lv_obj_set_height(ui_Panel1, 41);
    lv_obj_set_x(ui_Panel1, -43);
    lv_obj_set_y(ui_Panel1, -6);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockImg = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_clockImg, &ui_img_clock_rz_png);
    lv_obj_set_width(ui_clockImg, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clockImg, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_clockImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_clockImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_clockImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel2 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel2, 41);
    lv_obj_set_height(ui_Panel2, 41);
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, -6);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WetherImg = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_WetherImg, &ui_img_bar_chart_rz_png);
    lv_obj_set_width(ui_WetherImg, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WetherImg, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_WetherImg, 0);
    lv_obj_set_y(ui_WetherImg, -1);
    lv_obj_set_align(ui_WetherImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WetherImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_WetherImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel3 = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_Panel3, 41);
    lv_obj_set_height(ui_Panel3, 41);
    lv_obj_set_x(ui_Panel3, 42);
    lv_obj_set_y(ui_Panel3, -6);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MusicImg = lv_img_create(ui_Panel3);
    lv_img_set_src(ui_MusicImg, &ui_img_1888242194);
    lv_obj_set_width(ui_MusicImg, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MusicImg, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_MusicImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_MusicImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_MusicImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_btn_create(ui_MainScreen);
    lv_obj_set_width(ui_Button1, 74);
    lv_obj_set_height(ui_Button1, 14);
    lv_obj_set_x(ui_Button1, 3);
    lv_obj_set_y(ui_Button1, 23);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "CLOCK");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x020202), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

}