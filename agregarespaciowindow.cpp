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
