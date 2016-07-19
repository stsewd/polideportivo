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

private:
    Ui::AdminMainWindow *ui;
public:
    LoginWindow* loginWindow;
public:
    void cargarTablaEspacios();
    void cargarTablaEmpleados();
};

#endif // ADMINMAINWINDOW_H
