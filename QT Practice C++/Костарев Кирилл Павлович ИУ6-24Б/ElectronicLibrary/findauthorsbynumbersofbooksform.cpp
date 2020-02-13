#include "findauthorsbynumbersofbooksform.h"
#include "bookfile.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
findAuthorsByNumbersOfBooksForm::findAuthorsByNumbersOfBooksForm()
{
    this->setWindowTitle("Find All Books Of Authors");

    QVBoxLayout *layoutV1 = new QVBoxLayout();

    numberOfCopies = new QLabel("Enter Number Of Books", this);

    layoutV1->addWidget(numberOfCopies);

    QVBoxLayout *layoutV2 = new QVBoxLayout();
    numberOfCopiesEdit=new QLineEdit("", this);

    layoutV2->addWidget(numberOfCopiesEdit);

    QHBoxLayout *layoutG1 = new QHBoxLayout();

    layoutG1->addLayout(layoutV1);
    layoutG1->addLayout(layoutV2);

     QHBoxLayout *layoutG2 = new QHBoxLayout();

    btnFind=new QPushButton("Find", this);
    btnExit=new QPushButton("Back", this);

    layoutG2->addWidget(btnFind);
     layoutG2->addWidget(btnExit);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addLayout(layoutG1);
    layout->addLayout(layoutG2);

    connect(btnFind, SIGNAL(clicked(bool)),
              this,SLOT(findRecs()));
    connect(btnExit, SIGNAL(clicked(bool)),
              this,SLOT(close()));
}
void findAuthorsByNumbersOfBooksForm::findRecs()
{
    QString number = numberOfCopiesEdit->text();
    recType r;  // параметры поиска
    r.numberOfCopies = numberOfCopiesEdit->text();   //Здесь нужно сделать другой метод поиска так как
    winPrint.showResults(r, 2, number);                         //нужно будет не только введенное значение и больше его
    numberOfCopiesEdit->clear();
}
