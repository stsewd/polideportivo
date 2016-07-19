#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    cargarTablaEspacios();
    cargarTablaEmpleados();
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

void AdminMainWindow::cargarTablaEspacios()
{
    QStringList headers;
    headers << "#" << "Nombre" << "Capacidad" << "Tipo" << "Estado";

    ui->espaciosTable->setColumnCount(5);
    ui->espaciosTable->setHorizontalHeaderLabels(headers);
    // QHeaderView header;
    // header << "#" << "Test";
    // ui->espaciosTable->setHorizontalHeader(&header);

}

void AdminMainWindow::cargarTablaEmpleados()
{
    ui->empleadosTable->setColumnCount(5);
}
