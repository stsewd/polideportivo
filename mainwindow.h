#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginwindow.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class LoginWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_salirAction_triggered();

    void on_cerrarSesionAction_triggered();

    void on_reservarBtn_clicked();

private:
    Ui::MainWindow *ui;
public:
    LoginWindow* loginWindow;
    void cargarTablaEspacios();
    void cargarEspaciosDeportivos();
    void cargarEspaciosComplementarios();
};

#endif // MAINWINDOW_H
