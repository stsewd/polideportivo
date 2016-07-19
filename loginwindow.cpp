#include <string>

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "srv/empleadosrv.h"

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

    /*
    QString msg = QString::fromStdString(user + pass + tipoUsuario);

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
    */
    try {
        EmpleadoSrv es;

        if (tipoUsuario == "Administrador" && es.identificarUsuarioAdministrador(user, pass)) {
            adminWindow = new AdminMainWindow;
            adminWindow->loginWindow = this;
            adminWindow->show();
        } else if (es.identificarUsuario(user, pass)) {
            mainWindow = new MainWindow;
            mainWindow->loginWindow = this;
            mainWindow->show();
        }
        this->hide();
    } catch (std::string e) {
        QString msg = QString::fromStdString(e);
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    } catch (...) {
        QString msg = QString::fromStdString("Algo inesperado ocurrió.");
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    }
}
