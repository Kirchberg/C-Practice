#ifndef FINDAUTHORSBYPUBLISHINGANDYEARFORM_H
#define FINDAUTHORSBYPUBLISHINGANDYEARFORM_H
#include "printform.h"
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class findAuthorsByPublishingAndYearForm : public QWidget
{
    Q_OBJECT
    QLabel *publisher, *yearOfPublication;
    QLineEdit *publisherEdit, *yearOfPublicationEdit;
    QPushButton *btnFind, *btnExit;
    printForm winPrint;
public:
    findAuthorsByPublishingAndYearForm();        // конструктор
public slots:
    void findRecs();  // метод поиска записей
};

#endif // FINDAUTHORSBYPUBLISHINGANDYEARFORM_H
