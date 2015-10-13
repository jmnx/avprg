#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T10:26:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MidiInputExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
include(../drumstick/drumstick.pro)

