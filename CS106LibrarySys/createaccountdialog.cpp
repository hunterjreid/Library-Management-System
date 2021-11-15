#include "createaccountdialog.h"
#include "ui_createaccountdialog.h"
#include "mainwindow.h"
#include <QFileDialog>

createAccountDialog::createAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccountDialog)
{
    ui->setupUi(this);
    ui->passwordLn->setEchoMode(QLineEdit::Password);
}

createAccountDialog::~createAccountDialog()
{
    delete ui;
}

void createAccountDialog::on_createAccountBtn_clicked()
{
    //Open file
    QFile userFile("users.txt");
    userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&userFile);
    //Edit file new line
    out<<ui->emailLn->text()<<",";
    out<<ui->usernameLn->text()<<",";
    out<<ui->firstnameLn->text()<<",";
    out<<ui->passwordLn->text()<<Qt::endl;
    //Close "createaccount" dialog and console log.
    //qDebug() << "New Account Created: " << ui->usernameLn->text() << "- the User's pass is: " << ui->passwordLn->text();
    //emit singal back to mainwindow Sucessful login
    emit sendLogin(ui->usernameLn->text());
    //close dialog.
    this->close();
}

//Show Password by changing EchoMode
void createAccountDialog::on_checkBox_stateChanged(int showPassword)
{
    if (showPassword) {
        //Show
        ui->passwordLn->setEchoMode(QLineEdit::Normal);
    } else {
        //Hide
        ui->passwordLn->setEchoMode(QLineEdit::Password);
    }
}

