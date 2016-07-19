#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "srv/empleadosrv.h"
#include "srv/espaciocomplementariosrv.h"
#include "srv/espaciodeportivosrv.h"
#include "srv/empleadosrv.h"
#include "srv/sociosrv.h"
#include "srv/clientesrv.h"
#include "srv/tools.h"
#include "agregarespaciowindow.h"
#include "agregarempleadowindow.h"
#include "agregarsociowindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    cargarTablaEspacios();
    cargarTablaEmpleados();
    cargarTablaClientes();
    cargarTablaSocios();
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
    headers << "Nombre" << "Capacidad" << "Tipo" << "Estado";
    ui->espaciosTable->setColumnCount(4);
    ui->espaciosTable->setHorizontalHeaderLabels(headers);

    std::string tipoEspacio = ui->espaciosComboBox->currentText().toUtf8().constData();

    if (tipoEspacio == "Espacios deportivos") {
        cargarEspaciosDeportivos();
    } else if (tipoEspacio == "Espacios complementarios") {
        cargarEspaciosComplementarios();
    }
}

void AdminMainWindow::cargarTablaEmpleados()
{
    QStringList headers;
    headers << "Cédula" << "Nombre" << "Apellido" << "Administrador";
    ui->empleadosTable->setColumnCount(4);
    ui->empleadosTable->setHorizontalHeaderLabels(headers);
    cargarEmpleados();
}

void AdminMainWindow::cargarEspaciosDeportivos()
{
    EspacioDeportivoSrv eds;
    int n;
    for (EspacioDeportivo espacio : eds.get()) {
        n = ui->espaciosTable->rowCount();
        ui->espaciosTable->insertRow(n);
        ui->espaciosTable->setItem(n, 0, new QTableWidgetItem(tr(espacio.nombre.c_str())));
        ui->espaciosTable->setItem(n, 1, new QTableWidgetItem(espacio.capacidad));
        ui->espaciosTable->setItem(n, 2, new QTableWidgetItem(tr(espacio.tipo.nombre.c_str())));
        ui->espaciosTable->setItem(n, 3, new QTableWidgetItem(tr(estadoToString(espacio.estado).c_str())));
    }
}

void AdminMainWindow::cargarEspaciosComplementarios()
{
    EspacioComplementarioSrv ecs;
    int n;
    for (EspacioComplementario espacio : ecs.get()) {
        n = ui->espaciosTable->rowCount();
        ui->espaciosTable->insertRow(n);
        ui->espaciosTable->setItem(n, 0, new QTableWidgetItem(tr(espacio.nombre.c_str())));
        ui->espaciosTable->setItem(n, 1, new QTableWidgetItem(espacio.capacidad));
        ui->espaciosTable->setItem(n, 2, new QTableWidgetItem(tr(espacio.tipo.nombre.c_str())));
        ui->espaciosTable->setItem(n, 3, new QTableWidgetItem(tr(estadoToString(espacio.estado).c_str())));
    }
}

void AdminMainWindow::cargarEmpleados()
{
    EmpleadoSrv es;
    int n;
    auto* table = ui->empleadosTable;
    for (Empleado empleado : es.get()) {
        n = table->rowCount();
        table->insertRow(n);
        table->setItem(n, 0, new QTableWidgetItem(tr(empleado.cedula.c_str())));
        table->setItem(n, 1, new QTableWidgetItem(tr(empleado.nombre.c_str())));
        table->setItem(n, 2, new QTableWidgetItem(tr(empleado.apellido.c_str())));
        table->setItem(n, 3, new QTableWidgetItem(tr(empleado.esAdministrador ? "Si" : "No")));
    }
}

void AdminMainWindow::cargarSocios()
{
    SocioSrv ss;
    int n;
    auto* table = ui->sociosTable;
    for (Socio socio : ss.get()) {
        n = table->rowCount();
        table->insertRow(n);
        table->setItem(n, 0, new QTableWidgetItem(tr(socio.cedula.c_str())));
        table->setItem(n, 1, new QTableWidgetItem(tr(socio.nombre.c_str())));
        table->setItem(n, 2, new QTableWidgetItem(tr(socio.apellido.c_str())));
        table->setItem(n, 3, new QTableWidgetItem(tr(getFecha(&socio.fechaIngreso).c_str())));
    }
}

void AdminMainWindow::cargarTablaSocios()
{
    QStringList headers;
    headers << "Cédula" << "Nombre" << "Apellido" << "Fecha de afilacion";
    ui->sociosTable->setColumnCount(4);
    ui->sociosTable->setHorizontalHeaderLabels(headers);
    cargarSocios();
}

void AdminMainWindow::cargarClientes()
{
    ClienteSrv cs;
    int n;
    auto* table = ui->clientesTable;
    for (Cliente cliente: cs.get()) {
        n = table->rowCount();
        table->insertRow(n);
        table->setItem(n, 0, new QTableWidgetItem(tr(cliente.cedula.c_str())));
        table->setItem(n, 1, new QTableWidgetItem(tr(cliente.nombre.c_str())));
        table->setItem(n, 2, new QTableWidgetItem(tr(cliente.apellido.c_str())));
    }
}

void AdminMainWindow::cargarTablaClientes()
{
    QStringList headers;
    headers << "Cédula" << "Nombre" << "Apellido";
    ui->clientesTable->setColumnCount(3);
    ui->clientesTable->setHorizontalHeaderLabels(headers);
    cargarClientes();
}

void AdminMainWindow::on_espaciosComboBox_currentIndexChanged(int index)
{
    cargarTablaEspacios();
}

void AdminMainWindow::on_agregarEspacioBtn_clicked()
{
    AgregarEspacioWindow* window = new AgregarEspacioWindow();
    window->show();
}

void AdminMainWindow::on_agregarEmpleadoBtn_clicked()
{
    AgregarEmpleadoWindow* window = new AgregarEmpleadoWindow();
    window->show();
}

void AdminMainWindow::on_agregarSocioBtn_clicked()
{
    AgregarSocioWindow* window = new AgregarSocioWindow();
    window->show();
}
