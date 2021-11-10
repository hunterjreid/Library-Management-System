#include "createaccountdialog.h"
#include "ui_createaccountdialog.h"

createAccountDialog::createAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccountDialog)
{
    ui->setupUi(this);
}

createAccountDialog::~createAccountDialog()
{
    delete ui;
}
