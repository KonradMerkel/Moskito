#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T13:54:36
#
#-------------------------------------------------
include(../../lib/qextserialport-1.2rc/src/qextserialport.pri)

QT       += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WALL
TEMPLATE = app


SOURCES += ../main.cpp\
        ../mainwindow.cpp \
    ../settings.cpp

HEADERS  += ../mainwindow.h \
    ../settings.h \
    ../../lib/Kom_Moskito.h

FORMS    += ../mainwindow.ui \
    ../settings.ui

CONFIG   += qextserialport
