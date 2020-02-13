#include "findauthorsform.h"
#include "bookfile.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
findAuthorsForm::findAuthorsForm()
{
    this->setWindowTitle("Find All Books Of Authors");

    QVBoxLayout *layoutV1 = new QVBoxLayout();

    author = new QLabel("Enter The Author Of The Book", this);

    layoutV1->addWidget(author);

    QVBoxLayout *layoutV2 = new QVBoxLayout();
    authorEdit=new QLineEdit("", this);

    layoutV2->addWidget(authorEdit);

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
void findAuthorsForm::findRecs()
{
    QString number = "";
    recType r;  // параметры поиска
    r.author = authorEdit->text();
    winPrint.showResults(r, 1, number);
    authorEdit->clear();
}
