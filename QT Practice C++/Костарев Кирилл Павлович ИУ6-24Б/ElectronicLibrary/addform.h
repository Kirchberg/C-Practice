#ifndef ADDFORM_H
#define ADDFORM_H
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
class addForm : public QWidget
{
    Q_OBJECT
    QLabel *author, *name, *publisher, *yearOfPublication, *numberOfCopies;
    QLineEdit *authorEdit, *nameEdit, *publisherEdit, *yearOfPublicationEdit, *numberOfCopiesEdit;
    QPushButton *btnAdd, *btnExit;
public:
    addForm();
public slots:
    void addRecord();
};

#endif // ADDFORM_H
