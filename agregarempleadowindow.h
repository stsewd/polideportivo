#ifndef AGREGAREMPLEADOWINDOW_H
#define AGREGAREMPLEADOWINDOW_H

#include <QDialog>

namespace Ui {
class AgregarEmpleadoWindow;
}

class AgregarEmpleadoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarEmpleadoWindow(QWidget *parent = 0);
    ~AgregarEmpleadoWindow();

private:
    Ui::AgregarEmpleadoWindow *ui;
};

#endif // AGREGAREMPLEADOWINDOW_H
