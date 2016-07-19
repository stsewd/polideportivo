#ifndef AGREGARRESERVAWINDOW_H
#define AGREGARRESERVAWINDOW_H

#include <QDialog>

namespace Ui {
class AgregarReservaWindow;
}

class AgregarReservaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarReservaWindow(QWidget *parent = 0);
    ~AgregarReservaWindow();

private:
    Ui::AgregarReservaWindow *ui;
};

#endif // AGREGARRESERVAWINDOW_H
