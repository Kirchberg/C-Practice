#include "addform.h"
#include "bookfile.h"
#include "mainform.h"
#include <QVBoxLayout>
addForm::addForm()
{
    this->setWindowTitle("Create/Add Data About Author");

    QVBoxLayout *layoutV1 = new QVBoxLayout();

    author = new QLabel("Author", this);
    name = new QLabel("Name Of Book", this);
    publisher = new QLabel("Publisher", this);
    yearOfPublication = new QLabel("Year Of Publication",this);
    numberOfCopies= new QLabel("Number Of Copies", this);

    layoutV1->addWidget(author);
    layoutV1->addWidget(name);
    layoutV1->addWidget(publisher);
    layoutV1->addWidget(yearOfPublication);
    layoutV1->addWidget(numberOfCopies);

    QVBoxLayout *layoutV2 = new QVBoxLayout();

    authorEdit = new QLineEdit("", this);
    nameEdit = new QLineEdit("", this);
    publisherEdit = new QLineEdit("", this);
    yearOfPublicationEdit = new QLineEdit("", this);
    numberOfCopiesEdit = new QLineEdit("", this);

    layoutV2->addWidget(authorEdit);
    layoutV2->addWidget(nameEdit);
    layoutV2->addWidget(publisherEdit);
    layoutV2->addWidget(yearOfPublicationEdit);
    layoutV2->addWidget(numberOfCopiesEdit);

     QHBoxLayout *layoutG1 = new QHBoxLayout();

    layoutG1->addLayout(layoutV1);
    layoutG1->addLayout(layoutV2);

     QHBoxLayout *layoutG2 = new QHBoxLayout();

    btnAdd=new QPushButton("Add", this);
    btnExit=new QPushButton("Back",this);

    layoutG2->addWidget(btnAdd);
    layoutG2->addWidget(btnExit);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addLayout(layoutG1);
    layout->addLayout(layoutG2);

    connect(btnAdd, SIGNAL(clicked(bool)),this,SLOT(addRecord()));
    connect(btnExit, SIGNAL(clicked(bool)),this,SLOT(close()));
}
void addForm::addRecord()
{
    bookFile book;
    recType r;
    r.author = authorEdit->text();
    r.name = nameEdit->text();
    r.publisher = publisherEdit->text();
    r.yearOfPublication = yearOfPublicationEdit->text();
    r.numberOfCopies = numberOfCopiesEdit->text();
    authorEdit->clear();
    nameEdit->clear();
    publisherEdit->clear();
    yearOfPublicationEdit->clear();
    numberOfCopiesEdit->clear();
    book.addRec(r);
}
