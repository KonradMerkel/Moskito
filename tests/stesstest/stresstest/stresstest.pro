include(../../../lib/qextserialport-1.2rc/src/qextserialport.pri)

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stresstest
TEMPLATE = app


SOURCES += main.cpp

HEADERS  += ../../../lib/Kom_Moskito.h

FORMS    +=
