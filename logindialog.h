#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();

signals:
    void sendLogin(const QString &username);

private slots:

    void on_confrimBtn_clicked();

    void on_showPassCheckbox_stateChanged(int arg1);

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
