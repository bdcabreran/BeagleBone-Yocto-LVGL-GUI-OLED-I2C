// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SSD1306_LVGL

#include "../ui.h"

void ui_ClockScreen_screen_init(void)
{
    ui_ClockScreen = lv_obj_create(NULL);
    lv_obj_add_flag(ui_ClockScreen, LV_OBJ_FLAG_SCROLL_ONE);     /// Flags
    lv_obj_clear_flag(ui_ClockScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ClockScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ClockScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_ClockScreen);
    lv_obj_set_width(ui_Panel4, 37);
    lv_obj_set_height(ui_Panel4, 34);
    lv_obj_set_x(ui_Panel4, -43);
    lv_obj_set_y(ui_Panel4, -12);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel4, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_hour = lv_label_create(ui_Panel4);
    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_hour, "12");
    lv_obj_set_style_text_color(ui_hour, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_hour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_hour, &ui_font_SevenSegment, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_ClockScreen);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -20);
    lv_obj_set_y(ui_Label6, -21);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, ":");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &ui_font_SevenSegment, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel5 = lv_obj_create(ui_ClockScreen);
    lv_obj_set_width(ui_Panel5, 37);
    lv_obj_set_height(ui_Panel5, 34);
    lv_obj_set_x(ui_Panel5, 3);
    lv_obj_set_y(ui_Panel5, -12);
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel5, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_minute = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_minute, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_minute, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_minute, LV_ALIGN_CENTER);
    lv_label_set_text(ui_minute, "24");
    lv_obj_set_style_text_color(ui_minute, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_minute, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_minute, &ui_font_SevenSegment, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_ClockScreen);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 27);
    lv_obj_set_y(ui_Label3, -9);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, ".");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &ui_font_SevenSegment, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6 = lv_obj_create(ui_ClockScreen);
    lv_obj_set_width(ui_Panel6, 24);
    lv_obj_set_height(ui_Panel6, 21);
    lv_obj_set_x(ui_Panel6, 44);
    lv_obj_set_y(ui_Panel6, -6);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_Panel6, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel6, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_second = lv_label_create(ui_Panel6);
    lv_obj_set_width(ui_second, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_second, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_second, LV_ALIGN_CENTER);
    lv_label_set_text(ui_second, "35");
    lv_obj_set_style_text_color(ui_second, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_second, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_second, &ui_font_SevenSegmentSmall, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel7 = lv_obj_create(ui_ClockScreen);
    lv_obj_set_width(ui_Panel7, 119);
    lv_obj_set_height(ui_Panel7, 20);
    lv_obj_set_x(ui_Panel7, -1);
    lv_obj_set_y(ui_Panel7, 19);
    lv_obj_set_align(ui_Panel7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel7, lv_color_hex(0xFCFCFC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel7, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_date = lv_label_create(ui_Panel7);
    lv_obj_set_width(ui_date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_date, 1);
    lv_obj_set_y(ui_date, 1);
    lv_obj_set_align(ui_date, LV_ALIGN_CENTER);
    lv_label_set_text(ui_date, "Mar 25 / 2024");
    lv_obj_set_style_text_color(ui_date, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
