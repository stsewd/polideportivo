#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"

namespace Ui {
class AdminMainWindow;
}

class LoginWindow;

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = 0);
    ~AdminMainWindow();

private slots:

    void on_actionCerrarSesion_triggered();

    void on_actionSalir_triggered();

    void on_espaciosComboBox_currentIndexChanged(int index);

    void on_agregarEspacioBtn_clicked();

    void on_agregarEmpleadoBtn_clicked();

    void on_agregarSocioBtn_clicked();

    void on_eliminarEspacioBtn_clicked();

    void on_eliminarEmpleadoBtn_clicked();

    void on_eliminarClienteBtn_clicked();

    void on_eliminarSocioBtn_clicked();

private:
    Ui::AdminMainWindow *ui;
public:
    LoginWindow* loginWindow;
public:
    void cargarTablaEspacios();
    void cargarTablaEmpleados();
    void cargarEspaciosDeportivos();
    void cargarEspaciosComplementarios();
    void cargarEmpleados();
    void cargarSocios();
    void cargarTablaSocios();
    void cargarClientes();
    void cargarTablaClientes();
};

#endif // ADMINMAINWINDOW_H
