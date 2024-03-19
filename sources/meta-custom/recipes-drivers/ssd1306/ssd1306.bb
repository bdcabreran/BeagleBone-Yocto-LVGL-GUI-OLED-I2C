DESCRIPTION = "A simple Linux driver for the SSD1306 OLED."
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "file://ssd1306.c \
           file://Makefile \
          "

S = "${WORKDIR}"

inherit module

