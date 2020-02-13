#include "findauthorsbypublishingandyearform.h"
#include "bookfile.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
findAuthorsByPublishingAndYearForm::findAuthorsByPublishingAndYearForm()
{
    this->setWindowTitle("Find Authors By Publisher And Year Of Publication");

    QVBoxLayout *layoutV1 = new QVBoxLayout();

    publisher = new QLabel(("Enter Publisher"), this);
    yearOfPublication = new QLabel(("Enter Year Of Publication"), this);

    layoutV1->addWidget(publisher);
    layoutV1->addWidget(yearOfPublication);

    QVBoxLayout *layoutV2 = new QVBoxLayout();

    publisherEdit = new QLineEdit((""), this);
    yearOfPublicationEdit = new QLineEdit((""), this);

    layoutV2->addWidget(publisherEdit);
    layoutV2->addWidget(yearOfPublicationEdit);

     QHBoxLayout *layoutG1 = new QHBoxLayout();

    layoutG1->addLayout(layoutV1);
    layoutG1->addLayout(layoutV2);

     QHBoxLayout *layoutG2 = new QHBoxLayout();

    btnFind=new QPushButton(("Find"), this);
    btnExit=new QPushButton(("Back"), this);

    layoutG2->addWidget(btnFind);
    layoutG2->addWidget(btnExit);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addLayout(layoutG1);
    layout->addLayout(layoutG2);

    resize(450,100);

    connect(btnFind, SIGNAL(clicked(bool)),
              this,SLOT(findRecs()));
    connect(btnExit, SIGNAL(clicked(bool)),
              this,SLOT(close()));
}
void findAuthorsByPublishingAndYearForm::findRecs()
{
    QString number = "";
    recType r;  // параметры поиска
    r.publisher = publisherEdit->text();
    r.yearOfPublication = yearOfPublicationEdit->text(); //Здесь нужно сделать другой метод поиска так как
    winPrint.showResults(r, 3, number);                         //нужно будет не только введенное значение и больше его
    publisherEdit->clear();
    yearOfPublicationEdit->clear();
}
