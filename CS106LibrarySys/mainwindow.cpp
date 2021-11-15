#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "createaccountdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loginLb->setText("Not Logged In");
    ui->signOutBtn->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Login btn
void MainWindow::on_loginBtn_clicked()
{
    loginDialog dialog;
    dialog.setModal(true);
    connect(&dialog, &loginDialog::sendLogin, this, &MainWindow::receiveLogin);
    dialog.exec();
    //This func leads to receiveLogin if login is sucessful
}
//create account btn
void MainWindow::on_createAccountBtn_clicked()
{
    createAccountDialog dialog;
    dialog.setModal(true);
    connect(&dialog, &createAccountDialog::sendLogin, this, &MainWindow::receiveLogin);
    dialog.exec();
    //This func leads to receiveLogin if login is sucessful see below
}

void MainWindow::receiveLogin(const QString &username) {
    //login sucess.
    //qDebug() << username << " has logged in (Verifed login).";
    ui->loginLb->setText("Logged In As: " + username);
    ui->createAccountBtn->hide();
    ui->loginBtn->hide();
    ui->signOutBtn->show();

}

void MainWindow::on_signOutBtn_clicked()
{
    // Sign out btn clicked
    ui->signOutBtn->hide();
    ui->createAccountBtn->show();
    ui->loginBtn->show();
    ui->loginLb->setText("Not Logged In");
}

void MainWindow::on_bookRemove_clicked()
{
    // Remove book
    QListWidgetItem *it = ui->listWidget_books->takeItem(ui->listWidget_books->currentRow());
    delete it;
}

void MainWindow::on_addBookBtn_clicked()
{
    // add book (changed need) --- change to dialog
    QListWidgetItem *newBook = new QListWidgetItem;
    newBook->setText(ui->bookTitleLn->text());
    ui->listWidget_books->insertItem(0, newBook);
}
