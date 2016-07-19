#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::on_actionCerrarSesion_triggered()
{
    loginWindow->show();
    this->close();
}

void AdminMainWindow::on_actionSalir_triggered()
{
    this->close();
}
