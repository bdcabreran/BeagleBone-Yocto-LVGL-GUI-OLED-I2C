# test-ssd1306_1.0.bb

DESCRIPTION = "Simple application to test SSD1306 display on BeagleBone"
SECTION = "examples"
LICENSE = "CLOSED"

# Assuming no external source, if you have, use SRC_URI to fetch it.
SRC_URI = "file://main.c \
           file://Makefile\
           file://gif_code/exchange.c\
           file://gif_code/exchange.h\
           file://gif_code/global.c\
           file://gif_code/global.h\
           file://gif_code/penguin.c\
           file://gif_code/penguin.h\           
           file://img_code/rocket.c\
           file://img_code/rocket.h\    
           file://img_code/linux_img1.c\
           file://img_code/linux_img1.h\    
           file://img_code/linux_img2.c\
           file://img_code/linux_img2.h\                          
           "

# Specify where to install the binaries
S = "${WORKDIR}"

# Add dependencies required for your application here
DEPENDS = ""

# Specify the install task
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/test-ssd1306 ${D}${bindir}
}

# Let Yocto know what files we provide
FILES_${PN} += "${bindir}/test-ssd1306"

# Specify any additional tasks if necessary
