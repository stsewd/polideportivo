#include "agregarempleadowindow.h"
#include "ui_agregarempleadowindow.h"
#include "srv/empleadosrv.h"
#include <QMessageBox>

AgregarEmpleadoWindow::AgregarEmpleadoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarEmpleadoWindow)
{
    ui->setupUi(this);
}

AgregarEmpleadoWindow::~AgregarEmpleadoWindow()
{
    delete ui;
}

void AgregarEmpleadoWindow::on_btnCancelar_clicked()
{
    this->close();
}

void AgregarEmpleadoWindow::on_btnGuardar_clicked()
{
    try {
        EmpleadoSrv es;
        es.add(ui->txtCedula->text().toStdString(),
               ui->txtNombre->text().toStdString(),
               ui->txtApellido->text().toStdString(),
               ui->txtDireccion->text().toStdString(),
               ui->txtTelefono->text().toStdString(),
               ui->txtClave->text().toStdString(),
               ui->isAdministrador->isChecked());
        mainWindow->cargarTablaEmpleados();
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
