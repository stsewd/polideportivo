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
    srv/socio.cpp \
    dao/espaciodeportivodao.cpp \
    dao/espaciocomplementariodao.cpp \
    dao/clientedao.cpp \
    dao/sociodao.cpp \
    loginwindow.cpp \
    srv/empleado.cpp \
    dao/empleadodao.cpp \
    adminmainwindow.cpp \
    dao/conexiondb.cpp \
    srv/espaciodeportivosrv.cpp \
    srv/espaciocomplementariosrv.cpp \
    srv/clientesrv.cpp \
    srv/tools.cpp \
    srv/empleadosrv.cpp \
    srv/sociosrv.cpp \
    srv/reserva.cpp \
    dao/reservadao.cpp \
    srv/reservasrv.cpp \
    srv/factura.cpp \
    dao/facturadao.cpp \
    agregarespaciowindow.cpp


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
    dao/conexiondb.h \
    srv/espaciodeportivosrv.h \
    srv/espaciocomplementariosrv.h \
    srv/clientesrv.h \
    srv/tools.h \
    srv/empleadosrv.h \
    srv/sociosrv.h \
    dao/reservadao.h \
    srv/reservasrv.h \
    srv/factura.h \
    dao/facturadao.h \
    agregarespaciowindow.h



FORMS    += mainwindow.ui \
    loginwindow.ui \
    adminmainwindow.ui \
    agregarespaciowindow.ui

LIBS += -lmysqlcppconn

QMAKE_CXXFLAGS += -std=c++14
