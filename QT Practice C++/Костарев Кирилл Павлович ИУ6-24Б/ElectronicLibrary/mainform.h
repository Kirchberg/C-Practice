#ifndef MAINFORM_H
#define MAINFORM_H
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include "addform.h"
#include "printform.h"
#include "findauthorsform.h"
#include "findauthorsbynumbersofbooksform.h"
#include "findauthorsbypublishingandyearform.h"
#include "widget.h"


class Window: public QWidget
{
    Q_OBJECT
    QPushButton *btnAdd, *btnFindAuthors, *btnFindAuthorsByNumbersOfBooks,
                *btnFindAuthorsByPublishingAndYear, *btnDiagram,
                *btnDeleteData, *btnExit;
    addForm winAdd;
    findAuthorsForm winFindAuthors;
    findAuthorsByNumbersOfBooksForm winFindAuthorsByNumbersOfBooks;
    findAuthorsByPublishingAndYearForm winFindAuthorsByPublishingAndYear;
    Widget winWidget;
public:
    Window();
public slots:
    void showAdd();
    void showFindAuthors();
    void showFindAuthorsByNumbersOfBooks();
    void showFindAuthorsByPublishingAndYear();
    void showWidget();
    void DeleteData();
};

#endif // MAINFORM_H
