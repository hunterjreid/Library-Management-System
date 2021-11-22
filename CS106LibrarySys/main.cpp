#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
//MAIN APP START
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
