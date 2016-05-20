TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ../src/touch_clamp_hal.c \
    ../src/touch_clamp_hw.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../include/touch_clamp_hal.h \
    ../include/touch_clamp_hw.h

INCLUDEPATH += \
    ../include
