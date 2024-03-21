# Makefile

CC ?= gcc
CFLAGS = -Wall

# Include all source files here with their respective directories
SRCS = main.c \
       gif_code/exchange.c \
       gif_code/global.c \
       gif_code/penguin.c \
       img_code/rocket.c \
	   img_code/linux_img1.c \
	   img_code/linux_img2.c

# Object files are based on the source files
# This substitution command replaces '.c' with '.o' in source filenames
OBJS = $(SRCS:.c=.o)

all: test-ssd1306

# Link object files to create the executable
# $^ refers to all the dependencies in the rule, which are the object files in this case
test-ssd1306: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Compile source files into object files
# $< refers to the first dependency in the rule, which is a source file here
# $@ refers to the target of the rule, which is the object file here
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -f test-ssd1306 $(OBJS)
