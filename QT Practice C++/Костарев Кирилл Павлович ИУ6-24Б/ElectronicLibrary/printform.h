#ifndef PRINTFORM_H
#define PRINTFORM_H
#include "bookfile.h"
#include <QtGui>
#include <QTableWidget>
#include <QPushButton>
class printForm : public QWidget
{
    QTableWidget *table;  // таблица
    QPushButton *btnExit;
    void showRow(int i,recType r);// вывод строки таблицы
public:
    printForm();    // конструктор
    void showResults(recType r1, int p, QString number); // показать результаты поиска
};

#endif // PRINTFORM_H
