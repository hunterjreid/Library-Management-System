#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_loginBtn_clicked();

    void on_createAccountBtn_clicked();

    void receiveLogin(const QString &username);

    void on_signOutBtn_clicked();

    void on_listWidget_books_itemDoubleClicked(QListWidgetItem *item);

    void on_addBookAdmin_clicked();

private:
    Ui::MainWindow *ui;
    QVector<book*> bookList;
};
#endif // MAINWINDOW_H
