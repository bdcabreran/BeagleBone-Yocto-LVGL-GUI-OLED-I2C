FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
FILESPATH:prepend := "/yocto/build/workspace/sources/lvgl-demo-fb/oe-local-files:"
# srctreebase: /yocto/build/workspace/sources/lvgl-demo-fb

inherit externalsrc
# NOTE: We use pn- overrides here to avoid affecting multiple variants in the case where the recipe uses BBCLASSEXTEND
EXTERNALSRC:pn-lvgl-demo-fb = "/yocto/build/workspace/sources/lvgl-demo-fb"

# initial_rev: adf2c4490e17a1b9ec1902cc412a24b3b8235c8e
