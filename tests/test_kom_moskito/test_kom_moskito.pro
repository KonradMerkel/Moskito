
include(../../lib/qextserialport-1.2rc/src/qextserialport.pri)

QT       += core
QT       += testlib

QT       -= gui

TARGET = test_kom_moskito
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG   += qextserialport

HEADERS  += ../../lib/Kom_Moskito.h

SOURCES += main.cpp
