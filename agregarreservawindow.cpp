#include "agregarreservawindow.h"
#include "ui_agregarreservawindow.h"
#include "srv/espaciocomplementario.h"
#include "srv/espaciodeportivo.h"
#include "srv/espaciocomplementariosrv.h"
#include "srv/espaciodeportivosrv.h"
#include "srv/tools.h"
#include "srv/reservasrv.h"

#include <QDateTime>
#include <string>
#include <vector>
#include <ctime>

AgregarReservaWindow::AgregarReservaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarReservaWindow)
{
    ui->setupUi(this);
}

AgregarReservaWindow::~AgregarReservaWindow()
{
    delete ui;
}

void AgregarReservaWindow::on_cmbTipos_currentIndexChanged(int index)
{
    EspacioComplementarioSrv espacioCom;
    EspacioDeportivoSrv espacioDep;
    //QStringList listaEspaciosDeportivos=(QStringList()<<"Cancha de Tenis"<
    std::vector<EspacioComplementario> espaciosCom = espacioCom.get();
    std::vector<EspacioDeportivo> espaciosDep = espacioDep.get();
    QStringList listaED;
    QStringList listaEC;
    for(EspacioComplementario es : espaciosCom){
        listaEC.append(es.nombre);
    }
    for(EspacioDeportivo es : espaciosDep){
        listaED.append(es.nombre);
    }
    std::string tipo = ui->cmbTipos->currentText().toUtf8().constData();
    ui->cmbEspacios->clear();
    if(tipo == "Deportivo"){
        ui->cmbEspacios->addItems(listaED);
    }else if(tipo == "Complementario"){
        ui->cmbTipo->addItems(listaEC);
    }

}

void AgregarReservaWindow::on_cmbEspacios_currentIndexChanged(int index)
{
    EspacioComplementarioSrv espacioCom;
    EspacioDeportivoSrv espacioDep;
    std::string espacio = ui->cmbEspacios->currentText().toUtf8().constData();
    std::string tipo = ui->cmbTipos->currentText().toUtf8().constData();
    ui->txtPrecio->setText("");
    ui->txtEstado->setText("");
    if(tipo == "Deportivo"){
        EspacioDeportivo espacioDeportivo = espacioDep.get(espacio);
        ui->txtPrecio->setText(std::to_string(espacioDeportivo.precioPorhora));
        ui->txtEstado->setText(estadoToString(espacioDeportivo.estado));
    }else if(tipo == "Complementario"){
        EspacioComplementario espacioDeportivo = espacioCom.get(espacio);
        ui->txtPrecio->setText(std::to_string(espacioDeportivo.precioPorhora));
        ui->txtEstado->setText(estadoToString(espacioDeportivo.estado));
    }

}

void AgregarReservaWindow::on_btnGuardar_clicked()
{
    //QDateTime
    time_t fecha = (time_t) ui->date1->time();
    time_t fechaFinal = (time_t) ui->date2->time();
    std::string espacio = ui->cmbEspacios->currentText().toUtf8().constData();
    std::string tipo = ui->cmbTipos->currentText().toUtf8().constData();
    std::string cedula = ui->txtCedula->text().toStdString();
    ReservaSrv re;
    re.add(cedula,espacio,fecha,fechaFinal);
}
