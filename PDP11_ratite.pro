TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ratite_body.c \
    ratite_mem_funcs.c \
    memory_init.c \
    pipelatz.c \
    instructiondecoder.c \
    ratite_instructions.c

HEADERS += \
    definitions.h \
    ratite_mem_funcs.h \
    memory_init.h \
    ratite_body.h \
    pipelatz.h \
    instructiondecoder.h \
    ratite_instructions.h

DISTFILES += \
    logo.txt
