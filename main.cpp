#include "loginwindow.h"
#include "adminmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();
    return a.exec();
}
