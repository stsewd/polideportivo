#ifndef AGREGARSOCIOWINDOW_H
#define AGREGARSOCIOWINDOW_H

#include <QDialog>

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

private:
    Ui::AgregarSocioWindow *ui;
};

#endif // AGREGARSOCIOWINDOW_H
