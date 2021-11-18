#include "editbookdialog.h"
#include "ui_editbookdialog.h"
#include <QFileDialog>
#include "mainwindow.h"
#include "book.h"

editBookDialog::editBookDialog(book* editBook, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editBookDialog)
{
    ui->setupUi(this);
    this->editBook = editBook;

    qDebug() << editBook->isArchived();

    if(editBook->isArchived()) {



      ui->radioButton_hide->click();
    } else {

  ui->radioButton_show->click();
    }

    ui->title->setText(editBook->getName());
    ui->author->setText(editBook->getGenre());
    ui->text->setText(editBook->getWords());

}

editBookDialog::~editBookDialog()
{
    delete ui;
}

void editBookDialog::on_confirmbtn_clicked()
{



    if (ui->radioButton_show->isChecked()) {
        editBook->unArchived();
    } else if (ui->radioButton_hide->isChecked()) {
        editBook->setArchived();

    }


    editBook->setName((ui->title->text()));
    editBook->setGenre((ui->author->text()));
    editBook->setWords((ui->text->text()));



    this->close();


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
//            booksFile.resize(0);
//            b_file << s;
//            bookList[index]->switchArchived();
//            return;
//        }

}

