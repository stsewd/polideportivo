#ifndef AGREGAREMPLEADOWINDOW_H
#define AGREGAREMPLEADOWINDOW_H

#include <QDialog>
#include "adminmainwindow.h"

namespace Ui {
class AgregarEmpleadoWindow;
}

class AgregarEmpleadoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarEmpleadoWindow(QWidget *parent = 0);
    ~AgregarEmpleadoWindow();

private slots:
    void on_btnCancelar_clicked();

    void on_btnGuardar_clicked();

private:
    Ui::AgregarEmpleadoWindow *ui;
public:
    AdminMainWindow* mainWindow;
};

#endif // AGREGAREMPLEADOWINDOW_H
