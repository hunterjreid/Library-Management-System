#ifndef BOOK_H
#define BOOK_H
#include <QString>

class book
{
public:
    book(int archived, QString name, QString genre, QString imageFilePath = "none.png", QString words = "NO WORDS SET.",int canCheckout = 1);


    void checkOutBook();

    bool isArchived();
    void unArchived();

    void checkInBook();
    int canCheckoutFunc(); // <-- add these features

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
    int archived;
    int canCheckout;
    book();
};

#endif // BOOK_H
