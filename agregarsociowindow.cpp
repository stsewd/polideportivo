#include "agregarsociowindow.h"
#include "ui_agregarsociowindow.h"
#include "srv/sociosrv.h"
#include <QMessageBox>

AgregarSocioWindow::AgregarSocioWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarSocioWindow)
{
    ui->setupUi(this);
}

AgregarSocioWindow::~AgregarSocioWindow()
{
    delete ui;
}

void AgregarSocioWindow::on_btnGuardar_clicked()
{
    try {
        SocioSrv ss;
        ss.add(ui->txtCedula->text().toStdString(),
               ui->txtNombre->text().toStdString(),
               ui->txtApellido->text().toStdString(),
               ui->txtDireccion->text().toStdString(),
               ui->txtTelefono->text().toStdString());

        this->mainWindow->cargarTablaSocios();
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

void AgregarSocioWindow::on_btnCancelar_clicked()
{
    this->close();
}
