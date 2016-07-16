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
    srv/cliente.cpp \
    srv/espacio.cpp \
    srv/espaciocomplementario.cpp \
    srv/espaciodeportivo.cpp \
    srv/persona.cpp \
    srv/reserva.cpp \
    srv/socio.cpp \
    dao/espaciodeportivodao.cpp \
    dao/espaciocomplementariodao.cpp \
    dao/clientedao.cpp \
    dao/sociodao.cpp \
    loginwindow.cpp \
    srv/empleado.cpp \
    dao/empleadodao.cpp \
    adminmainwindow.cpp \
    srv/espaciosrv.cpp \
    dao/conexiondb.cpp

HEADERS  += mainwindow.h \
    srv/cliente.h \
    srv/espacio.h \
    srv/espaciocomplementario.h \
    srv/espaciodeportivo.h \
    srv/persona.h \
    srv/reserva.h \
    srv/socio.h \
    dao/espaciodeportivodao.h \
    dao/espaciocomplementariodao.h \
    dao/clientedao.h \
    dao/sociodao.h \
    loginwindow.h \
    srv/empleado.h \
    dao/empleadodao.h \
    adminmainwindow.h \
    srv/espaciosrv.h \
    dao/conexiondb.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    adminmainwindow.ui

LIBS += -lmysqlcppconn
