#ifndef AGREGARESPACIOWINDOW_H
#define AGREGARESPACIOWINDOW_H

#include <QDialog>
#include "adminmainwindow.h"

namespace Ui {
class AgregarEspacioWindow;
}

class AgregarEspacioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarEspacioWindow(QWidget *parent = 0);
    ~AgregarEspacioWindow();

private slots:
    void on_cmbTipoEspacio_currentIndexChanged(int index);

    void on_cmbTipoEspacio_activated(int index);

    void on_btnGuardar_clicked();

    void on_btnCancelar_clicked();

private:
    Ui::AgregarEspacioWindow *ui;
public:
    AdminMainWindow* mainWindow;
};

#endif // AGREGARESPACIOWINDOW_H
