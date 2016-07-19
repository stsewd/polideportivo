#ifndef AGREGARESPACIOWINDOW_H
#define AGREGARESPACIOWINDOW_H

#include <QDialog>

namespace Ui {
class AgregarEspacioWindow;
}

class AgregarEspacioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarEspacioWindow(QWidget *parent = 0);
    ~AgregarEspacioWindow();

private:
    Ui::AgregarEspacioWindow *ui;
};

#endif // AGREGARESPACIOWINDOW_H
