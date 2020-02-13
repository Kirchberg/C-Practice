#ifndef AREA_H
#define AREA_H
#include "figura.h"
#include <math.h>
#include <QWidget>
class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
    float a;
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyCircle *mycircle;
    MyAstr *myAstr;
    AstrAndCircle *AstrAndCirle;
protected:
//	обработчики событий
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};

#endif // AREA_H
