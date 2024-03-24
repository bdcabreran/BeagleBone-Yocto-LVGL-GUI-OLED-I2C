# ssd1306-tool.bb

DESCRIPTION = "Simple application to test SSD1306 driver on BeagleBone"
HOMEPAGE = "https://github.com/bdcabreran/ssd1306-tool"
SECTION = "examples"
LICENSE = "MIT"

# git md5sum LICENSE
LIC_FILES_CHKSUM = "file://LICENSE;md5=7b694e603a996c3bfdc6093ed1f70c8f"

SRC_URI = " \
    git://github.com/bdcabreran/ssd1306-tool.git;protocol=https;branch=develop \
"
# git rev-parse HEAD
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

EXTRA_OEMAKE = "CC='${CC}' CFLAGS='${CFLAGS}' LDFLAGS='${LDFLAGS}'"

# Add dependencies required for your application here
DEPENDS = "ssd1306-driver"

# Specify the install task
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/ssd1306-tool ${D}${bindir}
}

# Let Yocto know what files we provide
FILES_${PN} += "${bindir}/ssd1306-tool"

