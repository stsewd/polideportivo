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
