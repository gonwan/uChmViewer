# uChmViewer build script with qmake
#
#    Options:
#
# LIBZIP_ROOT - the root directory in which the zip library is installed
# CHMLIB_ROOT - the root directory in which the chm library is installed
# USE_STATIC_CHMLIB - if defined, static linkage to the chm library is used
# USE_WEBENGINE - if defined, WebEngine is used, otherwise WebKit is used
# USE_GETTEXT - if specified, the msgfmt command will be used to compile translations
#
###############################################################################

TEMPLATE = subdirs
SUBDIRS = lib src
src.depends = lib

include(common.pri)
include(po/po.pri)

unix {
    desktop.files = $${PROJECT_ROOT_DIR}/packages/freedesktop/uchmviewer.desktop
    desktop.path = $${PREFIX}/$${APP_DEF_DIR}

    ICONS_BASE_DIR = $${PROJECT_ROOT_DIR}/packages/freedesktop/icons
    icons.base = $${ICONS_BASE_DIR}
    icons.files = $$findFiles($$ICONS_BASE_DIR, *.png)
    icons.path = $${PREFIX}/$${APP_ICONS_DIR}

    INSTALLS += desktop icons
}

win32 {
}

macx {
}

!defined(VERSION, var): VERSION = $$getVersion()
message(Project version: $$VERSION)
