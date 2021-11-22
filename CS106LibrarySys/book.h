#ifndef BOOK_H
#define BOOK_H
#include <QString>

class book
{
public:
    book(int archived, QString name, QString genre, QString imageFilePath = "./none.png.", QString words = "NO WORDS SET.", QString author = "", QString added_date ="1/1/1970", QString checked_by="", QString return_date="");
    void setAuthor(QString author);
    QString getAuthor() const;
    void setAdded_date(QString added_date);
    QString getAdded_date() const;
    void setReturn_date(QString return_date);
    QString getReturn_date() const;
    void setChecked_by(QString checked_by);
    QString getChecked_by() const;
    bool isArchived();
    void unArchived();
    bool isDeleted();
    void deleteBook();
    void setName(QString name);
    QString getName() const;
    void setGenre(QString genre);
    QString getGenre() const;
    void setWords(QString words);
    QString getWords() const;
    void setImageFilePath(QString imageFilePath);
    QString getImageFilePath() const;
    void setArchived();
private:
    QString name;
    QString genre;
    QString imageFilePath;
    QString words;
    QString checked_by;
    QString author;
    QString added_date;
    QString return_date;
    int hidden;
    int archived;
    book();
};

#endif // BOOK_H
