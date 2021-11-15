#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_bookRemove_clicked();

    void on_addBookBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
