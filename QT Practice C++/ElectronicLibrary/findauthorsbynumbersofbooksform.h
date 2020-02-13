#ifndef FINDAUTHORSBYNUMBERSOFBOOKSFORM_H
#define FINDAUTHORSBYNUMBERSOFBOOKSFORM_H
#include "printform.h"
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class findAuthorsByNumbersOfBooksForm : public QWidget
{
    Q_OBJECT
    QLabel *numberOfCopies;
    QLineEdit *numberOfCopiesEdit;
    QPushButton *btnFind, *btnExit;
    printForm winPrint;
public:
    findAuthorsByNumbersOfBooksForm();        // конструктор
public slots:
    void findRecs();  // метод поиска записей
};

#endif // FINDAUTHORSBYNUMBERSOFBOOKSFORM_H
