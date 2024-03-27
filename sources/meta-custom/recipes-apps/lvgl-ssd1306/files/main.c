#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/display/SSD1306.h"
#include "lv_drivers/indev/evdev.h"
#include "lvgl_generated/ui.h"
// #include "ui.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define DISP_BUF_SIZE (128 * 1024)
void print_display_resolutions();
void print_lv_color_depth(void);
void lv_ex_hello_world(void);
void lv_ex_figures(void);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 8
    #error "LV_COLOR_DEPTH should be 8bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif


//////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 8
    #error "LV_COLOR_DEPTH should be 8bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////



static void set_x(void * var, int32_t v) {
    lv_obj_set_x(var, v);
}

void create_scrolling_text(void) {
    // Create a container object for the label. This acts as the reference for the scrolling area.
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 200, 50); // Set the size of the container
    lv_obj_center(obj); // Center the container on the screen

    // Create the label
    lv_obj_t * label = lv_label_create(obj);
    lv_label_set_text(label, "Happy Birthday bby <3!");
    lv_obj_add_flag(label, LV_OBJ_FLAG_FLOATING); // The label won't affect the container's layout
    lv_obj_update_layout(obj); // Update the layout to get correct sizes for animation setup
    lv_obj_set_style_text_font(label, &lv_font_montserrat_22, 0);

    // Prepare and start the animation
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, label);
    lv_anim_set_values(&a, lv_obj_get_width(obj) + 20, -lv_obj_get_width(label) - 20);
    lv_anim_set_time(&a, 6000); // Duration of the animation in milliseconds
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); // Repeat the animation indefinitely
    lv_anim_set_exec_cb(&a, set_x); // Function to be called for the animation
    lv_anim_start(&a);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TOTAL_SCREENS (4)
int current_screen_index = 0;

///////////////////////////////////////////////////////// Main Screen Demo //////////////////////////////////////////////////
static lv_obj_t *current_item = NULL;
static int current_item_index = 0;
lv_obj_t *items[3]; // Adjusted the size based on the actual number of items you have
static const int total_items = sizeof(items) / sizeof(items[0]); // Correctly calculate the total_items based on the array
static lv_timer_t *current_item_timer = NULL; // Timer for cycling through items

void update_item_selection(void) {
    // Clear the selection style from the current item
    if (current_item != NULL) {
        lv_obj_set_style_border_width(current_item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    
    // Move to the next item and apply the selection style
    current_item_index = (current_item_index + 1) % total_items;
    current_item = items[current_item_index];
    lv_obj_set_style_border_width(current_item, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    if(current_item == ui_Panel1) {
      lv_label_set_text(ui_Label1, "CLOCK");
    }
    else if (current_item == ui_Panel2) {
      lv_label_set_text(ui_Label1, "GRAPH");
    }
    else {
      lv_label_set_text(ui_Label1, "MUSIC");
    }
}


static void item_cycle_task(lv_timer_t *timer) {
    (void) timer; // Unused
    update_item_selection();
}

void setup_item_cycling(void) {

  items[0] = ui_Panel1;
  items[1] = ui_Panel2;
  items[2] = ui_Panel3;

  if (current_item_timer != NULL) {
    lv_timer_del(current_item_timer); // Ensure any existing timer is deleted before creating a new one
  }

  current_item_timer = lv_timer_create(item_cycle_task, 1000, NULL); // Change item every 1000 milliseconds (1 second)
}

///////////////////////////////////////////////////////// Clock Screen Demo //////////////////////////////////////////////////
static lv_timer_t *clock_demo_timer = NULL; // Timer for updating the clock demo

void update_clock_demo(void) {
    static int demo_seconds = 0;
    static int demo_minutes = 0;
    static int demo_hours = 0;
    char buffer[30]; // Buffer for formatting strings

    // Simulate time passing
    demo_seconds += 10; // Increment by 10 seconds for demonstration speed
    if (demo_seconds >= 60) {
        demo_seconds = 0;
        demo_minutes += 1; // Increment minutes as seconds overflow
    }
    if (demo_minutes >= 60) {
        demo_minutes = 0;
        demo_hours += 1; // Increment hours as minutes overflow
    }
    if (demo_hours >= 24) {
        demo_hours = 0; // Reset hours after a full day
    }

    // Update hour label
    snprintf(buffer, sizeof(buffer), "%02d", demo_hours);
    lv_label_set_text(ui_hour, buffer);

    // Update minute label
    snprintf(buffer, sizeof(buffer), "%02d", demo_minutes);
    lv_label_set_text(ui_minute, buffer);

    // Update second label
    snprintf(buffer, sizeof(buffer), "%02d", demo_seconds);
    lv_label_set_text(ui_second, buffer);

    // Optional: Update date label for demonstration (static date for simplicity)
    lv_label_set_text(ui_date, "Dec 31 / 2023");
}


void setup_clock_demo_timer(void) {
    if (clock_demo_timer != NULL) {
        lv_timer_del(clock_demo_timer); // Ensure any existing timer is deleted before creating a new one
    }
    clock_demo_timer = lv_timer_create(update_clock_demo, 100, NULL); // Update the clock every 1000 milliseconds (1 second)
}

//////////////////////////////////////////////// Graph Demo /////////////////////////////////////////////////////////////////
static lv_timer_t *chart_update_timer = NULL; // Timer for updating the chart data

static lv_coord_t data_set_1[] = {10, 20, 30, 20, 10, 15, 25, 35, 45, 40, 50, 60, 70, 80, 40};
static lv_coord_t data_set_2[] = {40, 35, 25, 15, 10, 20, 30, 20, 10, 15, 25, 35, 45, 55, 65};
static lv_coord_t data_set_3[] = {15, 10, 20, 30, 40, 35, 25, 15, 10, 20, 80, 40, 50, 60, 30};
static lv_coord_t data_set_4[] = {20, 30, 40, 35, 25, 15, 10, 20, 5, 40, 50, 2, 20, 60, 10};

static lv_coord_t *data_sets[] = { data_set_1, data_set_2, data_set_3, data_set_4 };
static int current_data_set_index = 0;
static const int total_data_sets = sizeof(data_sets) / sizeof(data_sets[0]);
lv_chart_series_t * ui_Chart1_series_1;

void update_chart_data(void) {
    // Move to the next data set and wrap around at the end
    current_data_set_index = (current_data_set_index + 1) % total_data_sets;
  
    // Assuming `ui_Chart1` is your chart object and `ui_Chart1_series_1` is the series you're updating
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, data_sets[current_data_set_index]);
}

void setup_chart_update_timer(void) {
    if (chart_update_timer != NULL) {
        lv_timer_del(chart_update_timer); // Ensure any existing timer is deleted before creating a new one
    }
    if ( ui_Chart1_series_1 == NULL)
    {
      ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x000000),LV_CHART_AXIS_SECONDARY_Y);
    }                                              
                                                                 
    chart_update_timer = lv_timer_create(update_chart_data, 500, NULL); // Update the chart every 500 milliseconds
}


//////////////////////////////////////////////// Music Demo /////////////////////////////////////////////////////////////////

static lv_timer_t *music_progress_timer = NULL; // Timer for updating the music progress

void update_progress(void) {
    static int progress = 0;
    progress += 1; // Increment progress. Adjust the increment rate as needed for your demo.
    if (progress > 100) { // Reset if it exceeds the maximum to simulate looping
        progress = 0;
    }
    
    lv_bar_set_value(ui_Bar1, progress, LV_ANIM_ON); // Update the progress bar value with animation
}

void setup_music_progress_timer(void) {
    if (music_progress_timer != NULL) {
        lv_timer_del(music_progress_timer); // Ensure any existing timer is deleted before creating a new one
    }
    music_progress_timer = lv_timer_create(update_progress, 100, NULL); // Update the progress every 100 milliseconds
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Animation executor function to set the opacity
void lv_disp_scr_animated(lv_obj_t * scr) {
    // Specify the type of animation, duration, and delay
    lv_scr_load_anim(scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);

    // Assuming `ui_MainScreen` is your main menu screen
    if (scr == ui_MainScreen) {
        printf("Setup item Cycling");
        setup_item_cycling(); // Start cycling items on the main menu
    } else {
        if (current_item_timer != NULL) {
            lv_timer_del(current_item_timer); // Stop cycling items when leaving the main menu
            current_item_timer = NULL;
        }
    }

    if (scr == ui_ClockScreen) {
        printf("Setup clock demo");
        setup_clock_demo_timer(); // Start updating the clock on the clock screen
    } else {
        if (clock_demo_timer != NULL) {
            lv_timer_del(clock_demo_timer); // Stop updating the clock when leaving the clock screen
            clock_demo_timer = NULL;
        }
    }

    if (scr == ui_GraphScreen) {
        printf("Setup chart data update");
        setup_chart_update_timer(); // Start updating the chart on the graph screen
    } else {
        if (chart_update_timer != NULL) {
            lv_timer_del(chart_update_timer); // Stop updating the chart when leaving the graph screen
            chart_update_timer = NULL;
        }
    }


    // Assuming `ui_MusicScreen` is your music screen object
    if (scr == ui_MusicScreen) {
        printf("Setup music progress demo");
        setup_music_progress_timer(); // Start updating the progress bar on the music screen
    } else {
        if (music_progress_timer != NULL) {
            lv_timer_del(music_progress_timer); // Stop updating the progress when leaving the music screen
            music_progress_timer = NULL;
        }
    }

}


void switch_to_next_screen(lv_obj_t *screen_cycle[]) {
    current_screen_index = (current_screen_index + 1) % TOTAL_SCREENS; // Move to next screen, wrap around if at the end
    lv_disp_scr_animated(screen_cycle[current_screen_index]); // Switch to the next screen with animation
}

static void cycle_screens_task(lv_timer_t *timer) {
    (void) timer; // Unused

    lv_obj_t *screen_cycle[] = {
        ui_MainScreen,
        ui_ClockScreen,
        ui_GraphScreen,
        ui_MusicScreen
    };

    switch_to_next_screen(screen_cycle);
}

void setup_screen_cycling(void) {
    lv_timer_create(cycle_screens_task, 5000, NULL); // Create a timer that calls cycle_screens_task every 3000 milliseconds (3 seconds)
}


int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux ssd1306 device init*/
    ssd1306_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = ssd1306_flush;
    disp_drv.hor_res    = 128;  // Set to your display width
    disp_drv.ver_res    = 64;   // Set to your display height
    lv_disp_drv_register(&disp_drv);

    // /*Create a Demo*/
    // lv_demo_widgets();
    print_display_resolutions();
    print_lv_color_depth();

//    Create a screen object and set its background to "white" (all pixels off for a typical OLED)

    /* Create a simple label */
    // lv_ex_hello_world();
    // lv_ex_figures();
    // ui_init();
    // create_scrolling_text();


    ui_init();

    setup_screen_cycling(); // Start cycling through the screens every 3 seconds


    // lv_obj_t * label = lv_label_create(lv_scr_act());
    // lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); // Set the label to scroll circularly
    // lv_label_set_text(label, "This is a scrolling text ");
    // lv_obj_set_width(label, 200); // Set the label width

    // Optional: Customize scrolling properties
    // lv_label_set_anim_speed(label, 30); // Set scrolling speed



    // ui_Screen1_screen_init();

    // Create a screen object and set its background to "white" (all pixels off for a typical OLED)
    // lv_obj_t *scr = lv_scr_act();
    // lv_obj_set_style_bg_color(scr, lv_color_white(), LV_PART_MAIN); // For OLED, "white" might mean turning pixels off

    // /* Create a rectangle */
    // lv_obj_t *rect = lv_obj_create(scr); // Parent is now our screen with modified background
    // lv_obj_set_size(rect, 50, 50);
    // lv_obj_align(rect, LV_ALIGN_CENTER, 0, 0); // Align the rectangle to the center of the screen
    // lv_obj_set_style_bg_color(rect, lv_color_black(), LV_PART_MAIN); // Set the rectangle color to black (visible as "white" here)
    // lv_obj_set_style_border_color(rect, lv_color_black(), LV_PART_MAIN); // Optional: set the border color if desired
    // lv_obj_set_style_radius(rect, 0, LV_PART_MAIN); // Make corners sharp

    /* Create a circle */
    // lv_obj_t *circle = lv_arc_create(scr); // Using the modified screen as parent
    // lv_arc_set_bg_angles(circle, 0, 360);
    // lv_obj_set_size(circle, 50, 50);
    // lv_obj_align(circle, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_remove_style(circle, NULL, LV_PART_KNOB);
    // // Set the circle color and remove its border to make it visibly "white" on the "black" background
    // lv_obj_set_style_bg_color(circle, lv_color_black(), LV_PART_MAIN); 
    // lv_obj_set_style_border_color(circle, lv_color_black(), LV_PART_MAIN);


    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}

void lv_ex_hello_world(void) {
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, world!");
        // Set the font of the label to lv_font_montserrat_14, one of the built-in fonts
    lv_obj_set_style_text_font(label, &lv_font_montserrat_18, 0);

    lv_obj_center(label);
}

void lv_ex_figures(void)
{
    /* Create a rectangle (using lv_obj) */
    lv_obj_t *rect = lv_obj_create(lv_scr_act()); // Create a basic object, which will be our rectangle
    lv_obj_set_size(rect, 100, 50); // Set the rectangle size
    lv_obj_align(rect, LV_ALIGN_CENTER, 0, -30); // Align the rectangle to the center of the screen, a little above the middle
    lv_obj_set_style_radius(rect, 0, 0); // Optional: Set the corner radius to 0 to make it a sharp rectangle

    /* Create a circle (using lv_arc) */
    lv_obj_t *circle = lv_arc_create(lv_scr_act()); // Create an arc, which will be used as a circle
    lv_arc_set_bg_angles(circle, 0, 360); // Set the background angle to make it a full circle
    lv_obj_set_size(circle, 50, 50); // Size of the circle. For a circle, width and height should be the same
    lv_obj_align(circle, LV_ALIGN_CENTER, 0, 50); // Align below the rectangle
    lv_obj_remove_style(circle, NULL, LV_PART_KNOB); // Remove the knob part of the arc to display it as a circle
}

void print_display_resolutions() {
    /* Assuming you have a display driver initialized and registered as disp_drv */
    lv_disp_t * disp = lv_disp_get_default();
    if (disp == NULL) {
        printf("Display is not initialized.\n");
        return;
    }

    lv_disp_drv_t * disp_drv = &disp->driver;
    if (disp_drv == NULL) {
        printf("Display driver is not accessible.\n");
        return;
    }

    /* Now, disp_drv should contain the current display's configurations, including resolutions */
    uint32_t hor_res = disp_drv->hor_res;
    uint32_t ver_res = disp_drv->ver_res;

    printf("Display resolution: Horizontal = %u, Vertical = %u\n", hor_res, ver_res);
}

void print_lv_color_depth(void) {
    printf("LV_COLOR_DEPTH is set to: %d\n", LV_COLOR_DEPTH);
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
