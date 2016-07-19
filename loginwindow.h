#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "mainwindow.h"
#include "adminmainwindow.h"

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class MainWindow;
class AdminMainWindow;

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_ingresarBtn_clicked();

private:
    Ui::LoginWindow *ui;

    AdminMainWindow* adminWindow;
    MainWindow* mainWindow;

};

#endif // LOGINWINDOW_H
