TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    pipeline.c \
    emulatorbody.c \
    emu_init_funcs.c

HEADERS += \
    pipeline.h \
    emulatorbody.h \
    emu_init_funcs.h

DISTFILES += \
    logo.txt
