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
    imageFilePath = editBook->getImageFilePath();
    QPixmap pixmap(editBook->getImageFilePath());
    ui->imagePreview->setPixmap(pixmap);
    ui->imagePreview->setScaledContents(true);
    ui->title->setText(editBook->getName());
    ui->authorLine->setText(editBook->getAuthor());
    ui->tags->setText(editBook->getGenre());
    ui->addedDateLabel->setText(editBook->getAdded_date());
    ui->plainTextEdit->setPlainText(editBook->getWords());
}

editBookDialog::~editBookDialog()
{
    delete ui;
}
void editBookDialog::on_confirmbtn_clicked()
{
   editBook->setName(ui->title->text());
   editBook->setAuthor(ui->authorLine->text());
   editBook->setGenre(ui->tags->text());
   editBook->setWords(ui->plainTextEdit->toPlainText());
   editBook->setImageFilePath(imageFilePath);
   this->close();
}
//Update image.
void editBookDialog::on_addImageBtn_clicked()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,
                                            "Open Image", "./",
                                            "Image Files (*.png *.jpg)");
    if (filename != "")
    {
        int lastSlash = filename.lastIndexOf("/");
        QString shortName = filename.right(filename.size() - lastSlash - 1);
        QFile::copy(filename, "./images/" + shortName);
        QPixmap pixmap("./images/" + shortName);
        ui->imagePreview->setPixmap(pixmap);
        ui->imagePreview->setScaledContents(true);
        //update internal data
        imageFilePath = "./images/" + shortName;
    } //end if
}

