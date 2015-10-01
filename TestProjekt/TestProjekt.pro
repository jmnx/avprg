#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T10:40:14
#
#-------------------------------------------------

QT       += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestProjekt
TEMPLATE = app

INCLUDEPATH += ../audioengine

SOURCES += main.cpp\
        mainwindow.cpp\
        oscillatorsource.cpp\
        sinus.cpp

HEADERS  += mainwindow.h\
        oscillatorsource.h\
        sinus.h

FORMS    += mainwindow.ui

include(../audioengine/audioplayer.pri)
