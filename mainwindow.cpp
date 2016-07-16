#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salirAction_triggered()
{
    this->close();
}

void MainWindow::on_cerrarSesionAction_triggered()
{
    loginWindow->show();
    this->close();
}
