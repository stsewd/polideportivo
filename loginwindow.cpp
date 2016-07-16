#include <string>

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_ingresarBtn_clicked()
{
    std::string user = ui->usuarioTextField->text().toUtf8().constData();
    std::string pass = ui->passTextField->text().toUtf8().constData();
    std::string tipoUsuario = ui->tipoUsuarioComboBox->currentText().toUtf8().constData();

    QString msg = QString::fromStdString(user + pass + tipoUsuario);

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();

    mainWindow = new MainWindow;
    mainWindow->loginWindow = this;
    mainWindow->show();
    this->hide();
}
