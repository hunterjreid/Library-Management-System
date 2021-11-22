#include "addbookdialog.h"
#include "ui_addbookdialog.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "mainwindow.h"

addBookDialog::addBookDialog(book*& newBook, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBookDialog)
{
    ui->setupUi(this);
    this->newBook = &newBook;
    imageFilePath = "./none.png"; //default
    connect(ui->addImageBtn, &QPushButton::clicked,
            this, &addBookDialog::loadItemImage);
    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        //create it!
        QDir().mkdir("./images");
    }
}
addBookDialog::~addBookDialog()
{
    delete ui;
}
void addBookDialog::on_confirmBtn_clicked()
{
//Confirm Btn path
    QString title = ui->TitleLn->text();
    QString genre = ui->genreLn->text();
    QString words = ui->wordsRaw->toPlainText();
    QString added_date =QDate::currentDate().toString();
    QString authorName = ui->authorLn->text();
    QString checked_by = "";
    QString return_date = "";
    if (title.trimmed() != "")
    {
        //Add book.
        *newBook = new book(0, title, genre, imageFilePath, words, authorName,added_date,checked_by,return_date);
        this->close();
    }
    else
    {
        //error path
        QMessageBox mb;
        mb.setText("You must have a valid name");
    }
}
void addBookDialog::loadItemImage()
{
    //load image
        QString filename;
        filename = QFileDialog::getOpenFileName(this, "Open Image", "./", "Image Files (*.png *.jpg)");
        if (filename != "")
        {
            int lastSlash = filename.lastIndexOf("/");
            QString shortName = filename.right(filename.size() - lastSlash - 1);
            QFile::copy(filename, "./images/" + shortName);
            QPixmap pixmap("./images/" + shortName);
            ui->imagePreview->setPixmap(pixmap);
            ui->imagePreview->setScaledContents(true);
            imageFilePath = "./images/" + shortName;
        }
}

