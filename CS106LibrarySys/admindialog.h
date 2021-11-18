#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include "book.h"
#include <QListWidgetItem>

namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminDialog(QWidget *parent = nullptr);
    ~adminDialog();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_createNew_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::adminDialog *ui;
    QVector<book*> bookList;
};

#endif // ADMINDIALOG_H
