FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://am335x-boneblack.dts \
    file://ssd1306.dtsi \
"

do_configure:append() {
    cp ${WORKDIR}/am335x-boneblack.dts ${S}/arch/arm/boot/dts/
    cp ${WORKDIR}/ssd1306.dtsi  ${S}/arch/arm/boot/dts/
}