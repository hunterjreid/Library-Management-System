#ifndef EDITBOOKDIALOG_H
#define EDITBOOKDIALOG_H

#include <QDialog>
#include "book.h"

namespace Ui {
class editBookDialog;
}

class editBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editBookDialog(book* editBook, QWidget *parent = nullptr);
    ~editBookDialog();

private slots:
    void on_confirmbtn_clicked();

private:
    Ui::editBookDialog *ui;
    book* editBook;
};

#endif // EDITBOOKDIALOG_H
