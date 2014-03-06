include(../../lib/qextserialport-1.2rc/src/qextserialport.pri)

QT       += core gui
QT += testlib

TARGET = MoskitoGUI
TEMPLATE = app


SOURCES += ../main.cpp\
        ../mainwindow.cpp \
    ../dialog_rec.cpp \
    ../manual.cpp

HEADERS  += ../mainwindow.h \
    ../dialog_rec.h \
    ../manual.h \
    ../../lib/Kom_Moskito.h

FORMS    += ../mainwindow.ui \
    ../dialog_rec.ui \
    ../manual.ui

CONFIG   += qextserialport

RESOURCES += \
    ../ressource.qrc
