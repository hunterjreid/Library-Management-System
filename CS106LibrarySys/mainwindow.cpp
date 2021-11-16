#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "createaccountdialog.h"
#include "addbookdialog.h"
#include "book.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loginLb->setText("Not Logged In");
    ui->signOutBtn->hide();

    //Load books
    QFile inputFile("books.txt");
    inputFile.open(QIODevice::ReadOnly |
                   QIODevice::Text);

    QTextStream in(&inputFile);
    ui->listWidget_books->clear();

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList info = line.split(",");
        //handle list of products ui
        ui->listWidget_books->addItem(info.at(0) + " - " + info.at(1));
        //handle vector
        book* newBook = new book(info.at(0),info.at(1),info.at(2),info.at(3));
        bookList.push_back(newBook);
    } //end while

    in.flush();
    inputFile.close();
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
//addBook (admin use only)
void MainWindow::on_addBookAdmin_clicked()
{
    book* newBook = nullptr;
    addBookDialog dialog(newBook, nullptr);
    dialog.setModal(true);
    dialog.exec();

    if (newBook != nullptr)
    {
        bookList.push_back(newBook);
        ui->listWidget_books->addItem(newBook->getName());
        QFile userFile("books.txt");
        userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
        QTextStream out(&userFile);
        //Edit file new line
        out<<newBook->getName()<<",";
        out<<newBook->getGenre()<<",";
        out<<newBook->getImageFilePath()<<",";
        out<<newBook->getWords()<<Qt::endl;
    }
}
void MainWindow::on_listWidget_books_itemDoubleClicked(QListWidgetItem *item)
{
    //change to edit mode if admin
    int index = item->listWidget()->currentRow();

    if (index != -1)
    {
        book* currentItem = bookList.at(index);

        if (currentItem != nullptr)
        {
            ui->titleLabel->setText(currentItem->getName());
            ui->authLabel->setText(currentItem->getGenre());
            ui->bookContentPlain->setPlainText(currentItem->getWords());


            QPixmap pixmap(currentItem->getImageFilePath());

            qDebug() << currentItem->getImageFilePath();

            ui->bookPreview->setPixmap(pixmap);

            ui->bookPreview->setScaledContents(true);
        } //end inner if
    } //end if
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



