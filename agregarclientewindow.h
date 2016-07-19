#ifndef AGREGARCLIENTEWINDOW_H
#define AGREGARCLIENTEWINDOW_H

#include <QDialog>

namespace Ui {
class AgregarClientewindow;
}

class AgregarClientewindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarClientewindow(QWidget *parent = 0);
    ~AgregarClientewindow();

private:
    Ui::AgregarClientewindow *ui;
};

#endif // AGREGARCLIENTEWINDOW_H
