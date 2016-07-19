#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "srv/espaciocomplementariosrv.h"
#include "srv/espaciodeportivosrv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cargarTablaEspacios();
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

void MainWindow::cargarTablaEspacios()
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

void MainWindow::cargarEspaciosDeportivos()
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

void MainWindow::cargarEspaciosComplementarios()
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

