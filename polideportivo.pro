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
    srv/administrador.cpp \
    srv/cliente.cpp \
    srv/espacio.cpp \
    srv/espaciocomplementario.cpp \
    srv/espaciodeportivo.cpp \
    srv/persona.cpp \
    srv/reserva.cpp \
    srv/socio.cpp

HEADERS  += mainwindow.h \
    srv/administrador.h \
    srv/cliente.h \
    srv/espacio.h \
    srv/espaciocomplementario.h \
    srv/espaciodeportivo.h \
    srv/persona.h \
    srv/reserva.h \
    srv/socio.h

FORMS    += mainwindow.ui

LIBS += -lmysqlcppconn
