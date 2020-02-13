#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)
{
    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::white);
    Painter->setPen(pen);
    dx= halflen * cos(Alpha);
    dy= halflen * sin(Alpha);
    draw(Painter);
}

void MyCircle::draw(QPainter *Painter)
{
    Painter->drawEllipse(QRect(x+dx,y+dy,r,r));
}

void MyAstr::draw(QPainter *Painter)
{
    int startAngle = 1*16;
    int spanAngle = (100/1.1) *16;
    Painter->drawArc(QRect(x+dx, y+dy, 80, 80), startAngle, spanAngle);
    startAngle = 1*16;
    spanAngle = -(100/1.1) *16;
    Painter->drawArc(QRect(x+dx, y+dy-80, 80, 80), startAngle, spanAngle);
    startAngle = (990) *16;
    spanAngle = -(100/1.1)*16;
    Painter->drawArc(QRect(x+dx+80, y+dy-80, 80, 80), startAngle, spanAngle);
    startAngle = -(990) *16;
    spanAngle = (90)*16;
    Painter->drawArc(QRect(x+dx+80, y+dy, 80, 80), startAngle, spanAngle);
}

void AstrAndCircle::draw(QPainter *Painter)
{
    Painter->drawEllipse(QRect(x+dx+41,y+dy-40,r,r));
    int startAngle = 1*16;
    int spanAngle = (100/1.2) *16;
    Painter->drawArc(QRect(x+dx, y+dy, 80, 80), startAngle, spanAngle);
    startAngle = 1*16;
    spanAngle = -(100/1.12) *16;
    Painter->drawArc(QRect(x+dx, y+dy-80, 80, 80), startAngle, spanAngle);
    startAngle = (990) *16;
    spanAngle = -(100/1.1)*16;
    Painter->drawArc(QRect(x+dx+80, y+dy-80, 80, 80), startAngle, spanAngle);
    startAngle = -(990) *16;
    spanAngle = (90)*16;
    Painter->drawArc(QRect(x+dx+80, y+dy, 80, 80), startAngle, spanAngle);
}
