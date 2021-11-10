#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "createaccountdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtn_clicked()
{
    loginDialog dialog;
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_createAccountBtn_clicked()
{
    createAccountDialog dialog;
    dialog.setModal(true);
    dialog.exec();
}

