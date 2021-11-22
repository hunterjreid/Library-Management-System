#include "book.h";
//Book class.
book::book(int archived, QString name, QString genre, QString imageFilePath, QString words, QString author, QString added_date, QString checked_by, QString return_date)
{
    this->name = name;
    this->genre = genre;
    this->imageFilePath = imageFilePath;
    this->words = words;
    this->checked_by = checked_by;
    this->archived = archived;
    this->author = author;
    this->return_date = return_date;
    this->added_date = added_date;
}
//Funcs.
void book::setAuthor(QString name)
{
    this->author = name;
}
QString book::getAuthor() const
{
    return author;
}
void book::setChecked_by(QString name)
{
    this->checked_by = name;
}
QString book::getChecked_by() const
{
    return checked_by;
}
void book::setAdded_date(QString name)
{
    this->added_date = name;
}
QString book::getAdded_date() const
{
    return added_date;
}
void book::setReturn_date(QString name)
{
    this->return_date = name;
}
QString book::getReturn_date() const
{
    return return_date;
}
bool book::isArchived() {
    if (this->archived == 0) {
        return false;
    } else {
        return true;
    }
}
bool book::isDeleted() {
    if (this->archived == -1) {
        return false;
    } else {
        return true;
    }
}
void book::deleteBook() {
    this->archived = -1;
}
void book::unArchived() {
        this->archived = 0;
}
void book::setArchived() {
        this->archived = 1;
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
//end book funcs.
