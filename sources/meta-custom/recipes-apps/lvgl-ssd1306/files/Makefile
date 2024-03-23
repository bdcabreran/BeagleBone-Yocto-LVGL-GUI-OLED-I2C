# Makefile

CC ?= gcc
CFLAGS = -Wall

# CFLAGS += -I/yocto/build/tmp/work/cortexa8hf-neon-poky-linux-gnueabi/lvgl/8.3.10/recipe-sysroot/usr/include
# LDFLAGS += -L/yocto/build/tmp/work/cortexa8hf-neon-poky-linux-gnueabi/lvgl/8.3.10/recipe-sysroot/usr/lib -llvgl


# Include all source files here with their respective directories
# SRCS = main.c \
#        folder1/file.c \
#        folder2/file2.c \

SRCS = main.c 

# Object files are based on the source files
# This substitution command replaces '.c' with '.o' in source filenames
OBJS = $(SRCS:.c=.o)

all: lvgl-ssd1306

# Link object files to create the executable
# $^ refers to all the dependencies in the rule, which are the object files in this case
lvgl-ssd1306: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Compile source files into object files
# $< refers to the first dependency in the rule, which is a source file here
# $@ refers to the target of the rule, which is the object file here
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -f lvgl-ssd1306 $(OBJS)
