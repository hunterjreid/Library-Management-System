#ifndef CREATEACCOUNTDIALOG_H
#define CREATEACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class createAccountDialog;
}

class createAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createAccountDialog(QWidget *parent = nullptr);
    ~createAccountDialog();

private:
    Ui::createAccountDialog *ui;
};

#endif // CREATEACCOUNTDIALOG_H
