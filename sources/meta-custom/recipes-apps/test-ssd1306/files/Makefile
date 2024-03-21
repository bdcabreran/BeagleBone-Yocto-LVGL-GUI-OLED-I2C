# Makefile

CC ?= gcc
CFLAGS = -Wall

all: test-ssd1306

test-ssd1306: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o test-ssd1306

clean:
	rm -f test-ssd1306
