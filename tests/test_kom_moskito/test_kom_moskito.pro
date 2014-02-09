
include(../../lib/qextserialport-1.2rc/src/qextserialport.pri)

QT       += core gui
QT       += testlib

TARGET = test_kom_moskito
CONFIG   += console

TEMPLATE = app

CONFIG   += qextserialport

HEADERS  += ../../lib/Kom_Moskito.h

SOURCES += main.cpp

FORMS +=
