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
