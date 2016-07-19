#ifndef FACTURAWINDOW_H
#define FACTURAWINDOW_H

#include <QDialog>

namespace Ui {
class FacturaWindow;
}

class FacturaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FacturaWindow(QWidget *parent = 0);
    ~FacturaWindow();

private:
    Ui::FacturaWindow *ui;
};

#endif // FACTURAWINDOW_H
