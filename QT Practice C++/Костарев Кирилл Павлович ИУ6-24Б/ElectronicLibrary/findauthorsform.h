#ifndef FINDAUTHORSFORM_H
#define FINDAUTHORSFORM_H
#include "printform.h"
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class findAuthorsForm : public QWidget
{
    Q_OBJECT
    QLabel *author;
    QLineEdit *authorEdit;
    QPushButton *btnFind, *btnExit;
    printForm winPrint;
public:
    findAuthorsForm();        // конструктор
public slots:
    void findRecs();  // метод поиска записей
};

#endif // FINDAUTHORSFORM_H
