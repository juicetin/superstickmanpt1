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
    background.cpp \
    stickman.cpp \
    settings.cpp \
    constants.cpp \
    gamemap.cpp

HEADERS  += dialog.h \
    background.h \
    stickman.h \
    settings.h \
    constants.h \
    gamemap.h

FORMS    += dialog.ui

RESOURCES +=
