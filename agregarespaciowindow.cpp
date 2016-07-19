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
    QStringList listaEspaciosDeportivos=(QStringList()<<"Cancha de Tenis"<<"Cancha de Futbol"<<"Cancha Sintética"<<"Cancha de Voley"<<"Estadio"<<"Piscina");
    QStringList listaEspaciosComplementarios=(QStringList()<<"Bar"<<"Sala de Conferencias"<<"Sala de Prensa"<<""<<"Tienda Deportiva");
    if(ui->cmbTipoEspacio->currentText().toUtf8().constData() == "Deportivo"){
        ui->cmbTipo->addItems(listaEspaciosDeportivos);
    }else if(ui->cmbTipoEspacio->currentText().toUtf8().constData() == "Deportivo"){
        ui->cmbTipo->addItems(listaEspaciosComplementarios);
    }

}
