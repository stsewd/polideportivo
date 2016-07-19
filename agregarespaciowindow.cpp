#include "agregarespaciowindow.h"
#include "ui_agregarespaciowindow.h"

AgregarEspacioWindow::AgregarEspacioWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarEspacioWindow)
{
    ui->setupUi(this);
}

AgregarEspacioWindow::~AgregarEspacioWindow()
{
    delete ui;
}

void AgregarEspacioWindow::on_cmbTipoEspacio_currentIndexChanged(int index)
{
    QStringList listaEspaciosDeportivos=(QStringList()<<"Cancha de Tenis"<<"Cancha de Futbol"<<"Cancha Sintetica"<<"Cancha de Voley"<<"Estadio"<<"Piscina");
    QStringList listaEspaciosComplementarios=(QStringList()<<"Bar"<<"Sala de Conferencias"<<"Sala de Prensa" << "Tienda Deportiva");
    std::string tipo = ui->cmbTipoEspacio->currentText().toUtf8().constData();
    ui->cmbTipo->clear();
    if(tipo == "Deportivo"){
        ui->cmbTipo->addItems(listaEspaciosDeportivos);
    }else if(tipo == "Complementario"){
        ui->cmbTipo->addItems(listaEspaciosComplementarios);
    }
}

void AgregarEspacioWindow::on_cmbTipoEspacio_activated(int index)
{
}
