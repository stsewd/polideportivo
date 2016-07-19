#include "agregarsociowindow.h"
#include "ui_agregarsociowindow.h"

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
