#include "book.h"

book::book(QString name, QString genre, QString imageFilePath, QString words, int canCheckout)
{
    this->name = name;
    this->genre = genre;
    this->imageFilePath = imageFilePath;
    this->words = words;
}
void book::checkOutBook() {
     this->canCheckout = 0;
}
void book::checkInBook() {
     this->canCheckout = 1;
}
int book::canCheckoutFunc() {

     return canCheckout;
}
void book::setName(QString name)
{
    this->name = name;
}
QString book::getName() const
{
    return name;
}
void book::setGenre(QString genre)
{
    this->genre = genre;
}
QString book::getGenre() const
{
    return genre;
}
void book::setWords(QString words)
{
    this->words = words;
}
QString book::getWords() const
{
    return words;
}
void book::setImageFilePath(QString imageFilePath)
{
    this->imageFilePath = imageFilePath;
}
QString book::getImageFilePath() const
{
    return imageFilePath;
}
