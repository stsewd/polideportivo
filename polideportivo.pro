#-------------------------------------------------
#
# Project created by QtCreator 2016-07-15T16:29:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polideportivo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    espacio.cpp \
    espaciodeportivo.cpp \
    espaciocoimplementario.cpp

HEADERS  += mainwindow.h \
    espacio.h \
    espaciodeportivo.h \
    espaciocoimplementario.h

FORMS    += mainwindow.ui

LIBS += -lmysqlcppconn
