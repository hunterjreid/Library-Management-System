#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "createaccountdialog.h"
#include "addbookdialog.h"
#include "editbookdialog.h"
#include "book.h"
#include <QFile>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loginLb->setText("Not Logged In");
    ui->signOutBtn->hide();

    //Load books
    QFile inputFile("books.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&inputFile);
    ui->listWidget_books->clear();

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList info = line.split(",");
        //handle list of products ui


        //handle vector



        int archived = info.at(0).split(" ")[0].toInt();
        qDebug() << archived;
        QString name = info.at(1);
        QString genre = info.at(2);

        ui->listWidget_books->addItem(info.at(1));
        book* newBook = new book(archived,name,genre,info.at(3));

//         book(int archived, QString name, QString genre, QString imageFilePath = "none.png", QString words = "NO WORDS SET.",int canCheckout = 1);
       bookList.push_back(newBook);


       if (archived) {
                      this->ui->listWidget_books->item(this->ui->listWidget_books->count()-1)->setForeground(Qt::red);
       } else {
                      this->ui->listWidget_books->item(this->ui->listWidget_books->count()-1)->setForeground(Qt::black);


       }

    } //end while

    in.flush();
    inputFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Login btn
void MainWindow::on_loginBtn_clicked()
{
    loginDialog dialog;
    dialog.setModal(true);
    connect(&dialog, &loginDialog::sendLogin, this, &MainWindow::receiveLogin);
    dialog.exec();
    //This func leads to receiveLogin if login is sucessful
}
//create account btn
void MainWindow::on_createAccountBtn_clicked()
{
    createAccountDialog dialog;
    dialog.setModal(true);
    connect(&dialog, &createAccountDialog::sendLogin, this, &MainWindow::receiveLogin);
    dialog.exec();
    //This func leads to receiveLogin if login is sucessful see below
}
//addBook (admin use only)
void MainWindow::on_addBookAdmin_clicked()
{
    book* newBook = nullptr;
    addBookDialog dialog(newBook, nullptr);
    dialog.setModal(true);
    dialog.exec();

    if (newBook != nullptr)
    {
        bookList.push_back(newBook);
        ui->listWidget_books->addItem(newBook->getName());
        QFile userFile("books.txt");
        userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
        QTextStream out(&userFile);
        //Edit file new line


        out<<"0,";
        out<<newBook->getName()<<",";
        out<<newBook->getGenre()<<",";
        out<<newBook->getImageFilePath()<<",";
        out<<newBook->getWords()<<Qt::endl;
    }
}



void MainWindow::on_save_clicked()
{
    QFile outputFile("books.txt");

    outputFile.open(QIODevice::WriteOnly |
                    QIODevice::Text);

    QTextStream out(&outputFile);

    for(book* book:bookList)
    {
        if (book->isArchived()) {
            out<<"1,";
        } else {
            out<<"0,";
        }

        out << book->getName()<<",";
        out << book->getGenre()<<",";
        out << book->getImageFilePath()<<",";
        out << book->getWords()<<Qt::endl;




    }
}
void MainWindow::on_listWidget_books_itemDoubleClicked(QListWidgetItem *item)
{
    //change to edit mode if admin
    int index = item->listWidget()->currentRow();

    if (index != -1)
    {
        book* currentItem = bookList.at(index);

        if (currentItem != nullptr)
        {
            ui->titleLabel->setText(currentItem->getName());
            ui->authLabel->setText(currentItem->getGenre());
            ui->bookContentPlain->setPlainText(currentItem->getWords());


            QPixmap pixmap(currentItem->getImageFilePath());

            qDebug() << currentItem->getImageFilePath();

            ui->bookPreview->setPixmap(pixmap);

            ui->bookPreview->setScaledContents(true);
        } //end inner if
    } //end if
}
void MainWindow::receiveLogin(const QString &username) {
    //login sucess.
    //qDebug() << username << " has logged in (Verifed login).";
    ui->loginLb->setText("Logged In As: " + username);

    ui->createAccountBtn->hide();
    ui->loginBtn->hide();
    ui->signOutBtn->show();

}
void MainWindow::on_signOutBtn_clicked()
{
    // Sign out btn clicked
    ui->signOutBtn->hide();
    ui->createAccountBtn->show();
    ui->loginBtn->show();
    ui->loginLb->setText("Not Logged In");
}

//MAKE CASE INSENTIVE!!!
//MAKE CASE INSENTIVE!!!

void MainWindow::on_searchBtn_clicked()
{
    QString searchQuery = ui->searchLn->text();
    int listWidgetSize = ui->listWidget_books->count();
    for (int k1 = 0; k1 < listWidgetSize; k1++)
        {
        if (ui->listWidget_books->item(k1)->text().startsWith(searchQuery))
        {
             ui->listWidget_books->item(k1)->setHidden(false);
        }
        else
        {
             ui->listWidget_books->item(k1)->setHidden(true);
        }
    }
}

//MAKE CASE INSENTIVE!!!
//MAKE CASE INSENTIVE!!!
void MainWindow::on_searchLn_textChanged(const QString &text)
{
    int listWidgetSize = ui->listWidget_books->count();
    for (int k1 = 0; k1 < listWidgetSize; k1++)
        {
        if (ui->listWidget_books->item(k1)->text().startsWith(text))
        {
             ui->listWidget_books->item(k1)->setHidden(false);
        }
        else
        {
             ui->listWidget_books->item(k1)->setHidden(true);
        }
    }
}


void MainWindow::on_archivedBtn_clicked()
{
    int index = ui->listWidget_books->currentIndex().row();

    if (index != -1)
    {
        book* SelectedBook = bookList.at(index);

        if (SelectedBook != nullptr)
        {
            editBookDialog editbookDialog(SelectedBook, nullptr);
            editbookDialog.exec();



        }//end inner if

        bool archived = bookList[index]->isArchived();
        if (!archived) {
             this->ui->listWidget_books->currentItem()->setForeground(Qt::black);
        } else {
             this->ui->listWidget_books->currentItem()->setForeground(Qt::red);
        }
    }//end if








}


//void MainWindow::on_archivedBtn_clicked() {
//    int index = ui->listWidget_books->currentIndex().row();
//    bool archived = bookList[index]->isArchived();
//    if (archived) {
//         this->ui->listWidget_books->currentItem()->setForeground(Qt::black);
//    } else {
//         this->ui->listWidget_books->currentItem()->setForeground(Qt::red);
//    }
//    QFile booksFile("books.txt");
//    booksFile.open(QIODevice::ReadWrite);
//    QTextStream b_file(&booksFile);

//    //do {
//        QString line = b_file.readLine();
//        QStringList data = line.split(",");
//        qDebug() << ui->listWidget_books->currentItem()->text();
//        qDebug() << bookList[index]->getName();

//        if ( ui->listWidget_books->currentItem()->text() == bookList[index]->getName() ) {
//            if (archived) {
//               data[0] = "0";
//            } else {
//               data[0] = "1";
//            }
//            QString s;
//            QString updated_ln = data.join(",");
//            s.append(updated_ln + "\n");

//            b_file << s;
//            bookList[index]->switchArchived();
//            return;
//        }

//    //} while (!b_file.atEnd());

//}




////        do {
////              QString line = b_file.readLine();
////              QStringList data = line.split(",");

////              qDebug() << ui->listWidget_books->currentItem()->text();
////              qDebug() << bookList[index]->getName();

////             if ((ui->listWidget_books->currentItem()->text()) == bookList[ui->listWidget_books->currentIndex().row()]->getName()) {

////                 if (archived) {
////                    data[0] = "0";
////                 } else {
////                    data[0] = "1";
////                 }
////                 QString s;
////                 QString updated_ln = data.join(",");
////                 s.append(updated_ln + "\n");
////                 line.resize(0);
////                 b_file << s;
////                 bookList[index]->switchArchived();
////                 break;
////             }
////        while (());
////        }
////}
////}









//         //            qDebug() << "running";

//         //            if (data.at(0) == "1") {
//         //                data[0] = "0";
//         //            } else {
//         //                data[0] = "1";
//         //            }
//         //            QString updated_ln = data.join(",");
//         //            qDebug() << updated_ln;
//         //            QString newline;
//         //            newline.append(updated_ln);
//         //            out << newline;
//         //        }






    //Edit line.




    //this->ui->listWidget_books->currentItem()->setHidden()






