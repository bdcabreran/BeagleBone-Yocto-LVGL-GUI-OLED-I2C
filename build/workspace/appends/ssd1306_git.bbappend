FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
FILESPATH:prepend := "/yocto/build/workspace/sources/ssd1306/oe-local-files:"
# srctreebase: /yocto/build/workspace/sources/ssd1306

inherit externalsrc
# NOTE: We use pn- overrides here to avoid affecting multiple variants in the case where the recipe uses BBCLASSEXTEND
EXTERNALSRC:pn-ssd1306 = "/yocto/build/workspace/sources/ssd1306"
EXTERNALSRC_BUILD:pn-ssd1306 = "/yocto/build/workspace/sources/ssd1306"

# initial_rev: bf886cd67ab4737557297dce01cdbceedc8e3e17
