#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class passwordDialog;
}

class passwordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit passwordDialog(QWidget *parent = nullptr);
    ~passwordDialog();

private slots:
    void on_btn1_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void check();

    void on_btn5_clicked();

    void on_btn9_clicked();

    void on_backbtn_clicked();

    void on_btn8_clicked();

    void on_btn9_2_clicked();

signals:
    void openAdminPass(); //login.

private:
    Ui::passwordDialog *ui;
    QString enteredPass;
    QString correctPass = "1234"; // CORRECT PASSWORD.
};

#endif // PASSWORDDIALOG_H
