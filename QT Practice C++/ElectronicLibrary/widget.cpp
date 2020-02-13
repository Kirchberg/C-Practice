#include "widget.h"
#include "qcustomplot.h"
#include "bookfile.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    resize(600,400);
    setWindowTitle(QString::fromUtf8("Diagram Of Distribution Of Books"));
    customPlot = new QCustomPlot(this);
    vbox = new QVBoxLayout(this);


    vbox->addWidget(customPlot);
    res = new QPushButton(QString::fromUtf8("Show Or Update Diagram"),this);
    btnExit = new QPushButton("Close", this);
    vbox->addWidget(res);
    vbox->addWidget(btnExit);
    setLayout(vbox);

    // Сигналы
    connect(res,SIGNAL(clicked()),this,SLOT(rndres()));
    connect(btnExit, SIGNAL(clicked()), this ,SLOT(close()));
}

void Widget::rndres()
{

    fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    customPlot->addPlottable(fossil);
    // Установки цвета:
    QPen pen;
    pen.setWidthF(2);//Толщина контура столбца
    fossil->setName(QString::fromUtf8("Books")); // Легенда
    pen.setColor(QColor(50, 50, 100));// Цвет контура столбца
    fossil->setPen(pen);
    // Цвет самого столбца, четвертый параметр - прозрачность
    fossil->setBrush(QColor(50, 50, 250, 70));

    bookFile book;
    int size = 0;
    book.findYears(size);
    int *mas1 = new int[size];
    int *mas2 = new int[size];

    for (int i = 0; i < size; i++)
        {
            mas2[i] = 1;
            mas1[i] = 0;
        }

    for (int i = 0; i < size; i++)
    {
        mas1[i] = book.a[i];
    }

    for (int i = 0; i < size - 1; i++)
        {
            for (int j = (size - 1); j > i; j--)
            {
                if (mas1[j - 1] > mas1[j])
                {
                    int temp = mas1[j - 1];
                    mas1[j - 1] = mas1[j];
                    mas1[j] = temp;
                }
            }
        }

    for (int i = 0; i < size - 1; i++)
        {
            for (int k = i + 1; k < size; k++)
            {
                if ((mas1[i] == mas1[k]) && (mas1[i] != 0) && (mas1[k] != 0))
                {
                    mas2[i]++;
                    mas1[k] = 0;
                    mas2[k]--;
                }
            }
        }

    // Установки значений оси X:
    int sizeXAxis = size;
    for (int i = 0; i < size; i++)
    {
        if ((mas2[i] == 0) || (mas1[i] == 0))
        {
            sizeXAxis--;
        }
    }
    QVector<double> ticks;
    QVector<QString> labels;
    for (int k = 0; k < sizeXAxis; k++)
    {
        ticks << k;
    }
    QString s;
    for (int i = 0; i < size;i++)
    {
        if (mas1[i] != 0)
        {
            s = QString::number(mas1[i]);
            labels << s;
        }
    }
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, sizeXAxis);
    customPlot->xAxis->setPadding(5);
    customPlot->xAxis->setLabel(QString::fromUtf8("Year Of Publication"));

    // Установки значений оси Y:
    int heightMax = 0;
    QVector<double> fossilData;
    for (int i = 0; i < size; i++)
    {
        if ((mas2[i] != 0) && (mas1[i] != 0))
        {
            fossilData << mas2[i];
            if(mas2[i] > heightMax)
            {
                heightMax = mas2[i];
            }
        }
    }
    fossil->setData(ticks, fossilData);
    customPlot->yAxis->setRange(0, heightMax + 5);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel(QString::fromUtf8("Number Of Books"));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Легенда:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    customPlot->replot();

    // Сброс всех установок графика:
    customPlot->removePlottable(fossil);
    delete [] mas1;
    delete [] mas2;
}
