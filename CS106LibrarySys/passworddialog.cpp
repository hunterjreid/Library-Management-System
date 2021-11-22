#include "passworddialog.h"
#include "admindialog.h"
#include "ui_passworddialog.h"
#include <QMessageBox>

passwordDialog::passwordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordDialog)
{
    ui->setupUi(this);

    enteredPass = "";
}
passwordDialog::~passwordDialog()
{
    delete ui;
}
void passwordDialog::check() {
    ui->label_2->setText(ui->label_2->text() + "*");
    if (enteredPass.length() == 4) {
        if (enteredPass == correctPass) {
            this->close();
            emit openAdminPass();
        } else {
            this->close();
        }
    }
}
void passwordDialog::on_btn1_clicked()
{
    enteredPass += "1";
    check();
}
void passwordDialog::on_btn3_clicked()
{
    enteredPass += "2";
    check();
}
void passwordDialog::on_btn4_clicked()
{
    enteredPass += "3";
    check();
}
void passwordDialog::on_btn6_clicked()
{
    enteredPass += "4";
    check();
}
void passwordDialog::on_btn7_clicked()
{
    enteredPass += "5";
    check();
}
void passwordDialog::on_btn5_clicked()
{
    enteredPass += "6";
    check();
}
void passwordDialog::on_btn9_clicked()
{
    enteredPass += "7";
    check();
}
void passwordDialog::on_backbtn_clicked()
{
    enteredPass += "8";
    check();
}
void passwordDialog::on_btn8_clicked()
{
    enteredPass += "9";
    check();
}
void passwordDialog::on_btn9_2_clicked()
{
    enteredPass += "0";
    check();
}

