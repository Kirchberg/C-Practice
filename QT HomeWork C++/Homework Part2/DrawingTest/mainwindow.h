#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include "area.h"
class Window : public QWidget
{
protected:
    Area *area;
    QPushButton *btn;
public:
    Window();
};
#endif // MAINWINDOW_H
