#include "mainform.h"
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QVBoxLayout>
Window::Window()
{
    this->setWindowTitle("Electronic Library");
    btnAdd = new QPushButton("Create/Add Data About Author", this);
    btnFindAuthors = new QPushButton("Find All Books Of Authors", this);
    btnFindAuthorsByNumbersOfBooks = new QPushButton("Find Authors By Numbers Of Books", this);
    btnFindAuthorsByPublishingAndYear = new QPushButton("Find Authors By Current Publishing And Current Year",this);
    btnDiagram = new QPushButton("Diagram Of Distribution Of Books",this);
    btnDeleteData = new QPushButton("Delete Data",this);
    btnExit = new QPushButton("Exit", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(btnAdd);
    layout->addWidget(btnFindAuthors);
    layout->addWidget(btnFindAuthorsByNumbersOfBooks);
    layout->addWidget(btnFindAuthorsByPublishingAndYear);
    layout->addWidget(btnDiagram);
    layout->addWidget(btnDeleteData);
    layout->addWidget(btnExit);

    resize(450,400);

    connect(btnAdd, SIGNAL(clicked()), this, SLOT(showAdd()));
    connect(btnFindAuthors, SIGNAL(clicked()), this, SLOT(showFindAuthors()));
    connect(btnFindAuthorsByNumbersOfBooks, SIGNAL(clicked()), this, SLOT(showFindAuthorsByNumbersOfBooks()));
    connect(btnFindAuthorsByPublishingAndYear, SIGNAL(clicked()), this, SLOT(showFindAuthorsByPublishingAndYear()));
    connect(btnDiagram, SIGNAL(clicked()), this, SLOT(showWidget()));
    connect(btnDeleteData, SIGNAL(clicked()), this, SLOT(DeleteData()));
    connect(btnExit, SIGNAL(clicked()), this, SLOT(close()));
}

void Window::showAdd()
{
    winAdd.show();
}

void Window::showFindAuthors()
{
    winFindAuthors.show();
}

void Window::showFindAuthorsByNumbersOfBooks()
{
    winFindAuthorsByNumbersOfBooks.show();
}

void Window::showFindAuthorsByPublishingAndYear()
{
    winFindAuthorsByPublishingAndYear.show();
}

void Window::showWidget()
{
    winWidget.show();
}

void Window::DeleteData()
{
    QFile("book.txt").remove();
}
