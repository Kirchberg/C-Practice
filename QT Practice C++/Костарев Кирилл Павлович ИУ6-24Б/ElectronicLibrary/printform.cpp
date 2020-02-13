#include "printform.h"
#include "mainform.h"
#include <QMessageBox>
#include <QHBoxLayout>
printForm::printForm()
{
     this->setWindowTitle("Result");
     QStringList strlist; // объект Список строк
     strlist << "Author" << "Name Of Book" << "Publisher" << "Number Of Copies" << "Year Of Publication"; // записываем строки заголовка
     table = new QTableWidget(20,5,this); // создаем таблицу
     table->setHorizontalHeaderLabels(strlist);// включаем
                                                                                                   //  заголовок
    QHBoxLayout *layoutG2 = new QHBoxLayout();

    btnExit=new QPushButton("Back", this);
    layoutG2->addWidget(btnExit);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(table);
    layout->addLayout(layoutG2);

    connect(btnExit, SIGNAL(clicked(bool)),this,SLOT(close()));
}
void printForm::showRow(int i,recType r)
{
    QTableWidgetItem *item; // элемент таблицы
     item = new QTableWidgetItem(); // создаем элемент
    item->setFlags(Qt::NoItemFlags);//запрещаем
                                                                                         // выделение
    item->setText(r.author);   // записываем текст
    table->setItem(i,0,item);// привязываем элемент
                                                                         // к таблице
    item = new QTableWidgetItem();// создаем элемент
    item->setFlags(Qt::NoItemFlags); //запрещаем
                                                                                         // выделение
    item->setText(r.name);
    table->setItem(i,1,item); // привязываем элемент

    item = new QTableWidgetItem();// создаем элемент
    item->setFlags(Qt::NoItemFlags); //запрещаем
                                                                                         // выделение
    item->setText(r.publisher); // записываем текст
    table->setItem(i,2,item); // привязываем элемент

    item = new QTableWidgetItem();// создаем элемент
    item->setFlags(Qt::NoItemFlags); //запрещаем

    item->setText(r.numberOfCopies); // записываем текст
    table->setItem(i,3,item); // привязываем элемент

    item = new QTableWidgetItem();// создаем элемент
    item->setFlags(Qt::NoItemFlags); //запрещаем

    item->setText(r.yearOfPublication); // записываем текст
    table->setItem(i,4,item); // привязываем элемент

    item = new QTableWidgetItem();// создаем элемент
    item->setFlags(Qt::NoItemFlags); //запрещаем
}

void printForm::showResults(recType r1, int p, QString number)
{
    bookFile book;
    if (!book.findFirst(r1, p, number))
    {   // если данные не найдены, то создаем сообщение
        QMessageBox msg(QMessageBox::Critical, "No Data", "No Data Found", QMessageBox::Ok, 0);
        msg.exec();
    }
    else
     {   // иначе - выводим результаты  по строкам
        showRow(0, book.r);
        int i = 0;
        while (book.findNext(r1, p, number))
             showRow(++i, book.r);
        table->setRowCount(i+1);
        resize(550,400);
        show();
     }
}
