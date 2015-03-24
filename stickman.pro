#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T23:01:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stickman
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    iofile.cpp \
    background.cpp \
    stickman.cpp

HEADERS  += dialog.h \
    iofile.h \
    background.h \
    stickman.h

FORMS    += dialog.ui

RESOURCES += \
    stickman.qrc
