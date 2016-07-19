#include "agregarempleadowindow.h"
#include "ui_agregarempleadowindow.h"

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
