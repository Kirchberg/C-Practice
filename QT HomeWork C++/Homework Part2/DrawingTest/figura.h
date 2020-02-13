#ifndef FIGURA_H
#define FIGURA_H
#include <QtGui>

class Figura
{
protected:
    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0;
public:
    Figura(int X,int Y,int Halflen):
                                 x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
};

class MyCircle: public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyCircle(int x,int y,int halflen, int ar):Figura(x,y,halflen)
    {
        r = ar;
    }
};

class MyAstr: public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyAstr(int x,int y,int halflen):Figura(x,y,halflen){}
};

class AstrAndCircle: public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    AstrAndCircle(int x, int y, int halflen, int ar): Figura(x,y,halflen)
    {
        r = ar;
    }
};

#endif // FIGURA_H
