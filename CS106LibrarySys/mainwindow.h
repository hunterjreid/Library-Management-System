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
    void receiveLogin(const QString &username);
    void on_listWidget_books_itemDoubleClicked(QListWidgetItem *item);
    void on_listWidget_books_itemPressed(QListWidgetItem *item);
    void on_searchLn_textChanged(const QString &arg1);
    //btns
    void on_loginBtn_clicked();
    void on_createAccountBtn_clicked();
    void on_signOutBtn_clicked();
    void on_addBookAdmin_clicked();
    void on_save_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_showPasswordBtn_clicked();
    void runAdmin();
private:
    Ui::MainWindow *ui;
    QVector<book*> bookList;
    QString username;
};
#endif // MAINWINDOW_H
