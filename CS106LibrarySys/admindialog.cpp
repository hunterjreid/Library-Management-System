#include "admindialog.h"
#include "ui_admindialog.h"
#include "book.h"
#include <QFile>
#include <QString>
#include "editbookdialog.h"
#include "addbookdialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    //Load books
    QFile inputFile("books.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&inputFile);
    ui->listWidget_aBooks->clear();

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

        ui->listWidget_aBooks->addItem(info.at(1));
        book* newBook = new book(archived,name,genre,info.at(3));

//         book(int archived, QString name, QString genre, QString imageFilePath = "none.png", QString words = "NO WORDS SET.",int canCheckout = 1);
       bookList.push_back(newBook);





       if (archived == 1) {
                      this->ui->listWidget_aBooks->item(this->ui->listWidget_aBooks->count()-1)->setForeground(Qt::red);
       } else if (archived == -1) {
           this->ui->listWidget_aBooks->item(this->ui->listWidget_aBooks->count()-1)->setHidden(true);
} else {
                      this->ui->listWidget_aBooks->item(this->ui->listWidget_aBooks->count()-1)->setForeground(Qt::black);


       }



    } //end while

    in.flush();
    inputFile.close();




}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_pushButton_3_clicked()
{

    int index = ui->listWidget_aBooks->currentIndex().row();


        bool archived = bookList[index]->isArchived();
        qDebug() << archived;
        if (!archived) {

            bookList[index]->setArchived();
            this->ui->listWidget_aBooks->item(index)->setForeground(Qt::red);

       }
       else
       {
            bookList[index]->unArchived();
               this->ui->listWidget_aBooks->item(index)->setForeground(Qt::black);
        }








    }




void adminDialog::on_pushButton_4_clicked()
{
    QFile outputFile("books.txt");

    outputFile.open(QIODevice::WriteOnly |
                    QIODevice::Text);

    QTextStream out(&outputFile);

    for(book* book:bookList)
    {
        if (!book->isDeleted()) {
            out<<"-1,";
        }

        else if (book->isArchived()) {
            out<<"1,";
        } else {
            out<<"0,";
        }

        out << book->getName()<<",";
        out << book->getGenre()<<",";
        out << book->getImageFilePath()<<",";
        out << book->getWords()<<Qt::endl;




    }


    this->close();
}


void adminDialog::on_createNew_clicked()
{

    book* newBook = nullptr;
    addBookDialog dialog(newBook, nullptr);
    dialog.setModal(true);
    dialog.exec();

    if (newBook != nullptr)
    {
        bookList.push_back(newBook);
        ui->listWidget_aBooks->addItem(newBook->getName());

    }


}
void adminDialog::on_pushButton_5_clicked()
{
    int index = ui->listWidget_aBooks->currentIndex().row();
    bookList[index]->deleteBook();
    this->ui->listWidget_aBooks->item(index)->setHidden(true);



}


void adminDialog::on_pushButton_2_clicked()


{



    int index = ui->listWidget_aBooks->currentIndex().row();

    if (index != -1)
    {
        book* currentBook = bookList.at(index);

        if (currentBook != nullptr)
        {
            editBookDialog updateItemDialog(currentBook, nullptr);
            updateItemDialog.exec();

            //make sure UI is updated
            ui->listWidget_aBooks->item(index)->setText(currentBook->getName());
        }
    }
}








