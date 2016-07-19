#include "facturawindow.h"
#include "ui_facturawindow.h"

FacturaWindow::FacturaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FacturaWindow)
{
    ui->setupUi(this);
}

FacturaWindow::~FacturaWindow()
{
    delete ui;
}
