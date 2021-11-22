#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QFileDialog>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->passwordLn->setEchoMode(QLineEdit::Password);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_confrimBtn_clicked()
{
    //read data
    QString emailLn = ui->emailLn->text();
    QString passwordLn = ui->passwordLn->text();
    // if found bool will change to true
    found = false;
    //open user file
    QFile users("users.txt");
    if (users.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&users);
        while (!in.atEnd())
        {
            //read line by line.
            QString line = in.readLine();
            QStringList info = line.split(",");
            //qDebug() << line << " --- all details";
            //find strings to match
            QString usernameCorrect = info.at(1);
            QString passwordCorrect = info.at(3);
            //check for match
            if(emailLn==usernameCorrect&&passwordLn==passwordCorrect) {
               this->close();
               found = true;
               users.close();
               emit sendLogin(usernameCorrect);
               return;
           }
       }
       if (!found) {
           //if not found return.
           QMessageBox::warning(this,"Login","Username and Password is incorrect");
           return;
       }
       users.close();
    }
}
//show/hide password logic.
void loginDialog::on_showPassCheckbox_stateChanged(int showPassword)
{
    if (showPassword) {
        //Show
        ui->passwordLn->setEchoMode(QLineEdit::Normal);
    } else {
        //Hide
        ui->passwordLn->setEchoMode(QLineEdit::Password);
    }
}

