#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

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
    //extrapolate Data
    QString emailLn = ui->emailLn->text();
    QString passwordLn = ui->passwordLn->text();
    ui->passwordLn->setText("");

    if (emailLn == "123@gmail.com" && passwordLn == "123") {
        this->close();
    } else {
        QMessageBox::information(this, "Login", "Incorrect Email or Password");
    }
}


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

