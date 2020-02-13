#include "area.h"
#include <math.h>
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(600,250));
    mycircle = new MyCircle(50,50,50,35);
    myAstr = new MyAstr(200,100,50);
    AstrAndCirle = new AstrAndCircle(450,120,20,80);
    alpha= M_PI;
    a = 0.1;
}
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(30);
}
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    myAstr->move(alpha*1.09/2*M_PI,&painter);
    AstrAndCirle->move(-alpha*0.7,&painter);

    if((alpha > 2 * M_PI) ||(alpha < M_PI - 0.001))
    {
        a = -a;
        mycircle->move((alpha),&painter);
    }
    else
    {
        mycircle->move((-alpha),&painter);
    }
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)
    {
       alpha = alpha + a;
       update();
    }
    else
       QWidget::timerEvent(event);
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer);
}
Area::~Area()
{
    delete mycircle;
    delete myAstr;
    delete AstrAndCirle;
}
