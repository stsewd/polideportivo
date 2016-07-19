#ifndef AGREGARSOCIOWINDOW_H
#define AGREGARSOCIOWINDOW_H

#include <QDialog>
#include "adminmainwindow.h"

namespace Ui {
class AgregarSocioWindow;
}

class AgregarSocioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarSocioWindow(QWidget *parent = 0);
    ~AgregarSocioWindow();

private slots:
    void on_btnGuardar_clicked();

    void on_btnCancelar_clicked();

private:
    Ui::AgregarSocioWindow *ui;
public:
    AdminMainWindow* mainWindow;
};

#endif // AGREGARSOCIOWINDOW_H
