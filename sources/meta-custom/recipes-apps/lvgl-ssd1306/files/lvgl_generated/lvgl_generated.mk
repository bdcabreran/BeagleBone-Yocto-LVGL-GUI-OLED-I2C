LVGL_GENERATED_DIR_NAME ?= lvgl_generated

override CFLAGS := -I$(LVGL_DIR) $(CFLAGS)

CSRCS += $(wildcard $(LVGL_DIR)/$(LVGL_GENERATED_DIR_NAME)/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/$(LVGL_GENERATED_DIR_NAME)/components/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/$(LVGL_GENERATED_DIR_NAME)/fonts/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/$(LVGL_GENERATED_DIR_NAME)/images/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/$(LVGL_GENERATED_DIR_NAME)/screens/*.c)
