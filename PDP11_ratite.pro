TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    logobin.c \
    pipeline.c

HEADERS += \
    logobin.h \
    pipeline.h

DISTFILES += \
    logo.txt
