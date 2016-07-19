#include "agregarespaciowindow.h"
#include "ui_agregarespaciowindow.h"
#include "srv/espaciocomplementariosrv.h"
#include "srv/espaciodeportivosrv.h"
#include <QMessageBox>

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

void AgregarEspacioWindow::on_btnGuardar_clicked()
{
    try {
        EspacioComplementarioSrv ecs;
        EspacioDeportivoSrv eds;

        std::string tipo = ui->cmbTipoEspacio->currentText().toUtf8().constData();
        Horario h;
        h.entrada.hora = atoi(ui->txtHorarioEntrada->text().toStdString().c_str());
        h.entrada.minuto = 0;
        h.salida.hora = atoi(ui->txtHorarioSalida->text().toStdString().c_str());
        h.salida.minuto = 0;

        if(tipo == "Deportivo"){
            eds.add(ui->txtNombre->text().toStdString(),
                    ui->txtDescripcion->text().toStdString(),
                    std::atof(ui->txtPrecioPorHora->text().toStdString().c_str()),
                    std::atoi(ui->txtCapacidad->text().toStdString().c_str()),
                    ui->cmbEstado->currentText().toStdString(),
                    h,
                    ui->cmbTipoEspacio->currentText().toStdString());
        }else if(tipo == "Complementario"){
            ecs.add(ui->txtNombre->text().toStdString(),
                    ui->txtDescripcion->text().toStdString(),
                    std::atof(ui->txtPrecioPorHora->text().toStdString().c_str()),
                    std::atoi(ui->txtCapacidad->text().toStdString().c_str()),
                    ui->cmbEstado->currentText().toStdString(),
                    h,
                    ui->cmbTipoEspacio->currentText().toStdString());
        }

        this->mainWindow->cargarTablaEspacios();
        this->close();
    } catch (std::string e) {
        QString msg = QString::fromStdString(e);
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    } catch (...) {
        QString msg = QString::fromStdString("Algo inesperado ocurrió.");
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    }
}

void AgregarEspacioWindow::on_btnCancelar_clicked()
{
    this->close();
}
