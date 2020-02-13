#ifndef WIDGET_H
#define WIDGET_H
#include <QVBoxLayout>
#include <QPushButton>
#include "qcustomplot.h"
#include "bookfile.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

private:
    int key;
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;
    QPushButton *res, *btnExit;
    QCPBars *fossil;

private slots:
    void rndres();
};

#endif // WIDGET_H
