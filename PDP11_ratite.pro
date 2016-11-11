TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    pipeline.c \
    emulatorbody.c \
    emu_init_funcs.c \
    mem_funcs.c \
    operations.c

HEADERS += \
    emulatorbody.h \
    emu_init_funcs.h \
    mem_funcs.h \
    pipeline.h \
    pipeline.h

DISTFILES += \
    logo.txt
