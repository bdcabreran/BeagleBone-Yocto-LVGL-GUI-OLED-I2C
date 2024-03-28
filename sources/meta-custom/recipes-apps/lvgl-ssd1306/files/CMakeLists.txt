cmake_minimum_required(VERSION 3.1)

project(lvgl_ssd1306)

include_directories(.)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(lvgl_generated)

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lvgl/demos/*.h"  "lvgl/*.h"  "./*.h" "lvgl_generated/*.h")
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "lvgl/demos/*.c"  "lvgl/src/*.c" "lvgl_generated/*.c")

# add_executable(${PROJECT_NAME} main.c mouse_cursor_icon.c)
add_executable(${PROJECT_NAME} main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})

target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm drm)
