FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += " \
    file://am335x-boneblack.dts \
    file://ssd1306.dtsi \
"

#do_compile:append() {
#    cp ${WORKDIR}/am335x-boneblack.dts ${S}/arch/arm/boot/dts/${PN}/
#    cp ${WORKDIR}/ssd1306.dtsi ${S}/arch/arm/boot/dts/${PN}/
#}
