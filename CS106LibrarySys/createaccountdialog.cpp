#include "createaccountdialog.h"
#include "ui_createaccountdialog.h"

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

