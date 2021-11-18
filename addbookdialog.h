#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class addBookDialog;
}

class addBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addBookDialog(book*& newBook, QWidget *parent = nullptr);
    ~addBookDialog();
     void addImage();
     void loadItemImage();

private slots:
    void on_confirmBtn_clicked();

private:
    Ui::addBookDialog *ui;
    book** newBook;
    QString imageFilePath;
};

#endif // ADDBOOKDIALOG_H
