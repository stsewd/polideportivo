#include "agregarclientewindow.h"
#include "ui_agregarclientewindow.h"

AgregarClientewindow::AgregarClientewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarClientewindow)
{
    ui->setupUi(this);
}

AgregarClientewindow::~AgregarClientewindow()
{
    delete ui;
}

void AgregarClientewindow::on_btnGuardar_clicked()
{
    try {
        // TODO
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
