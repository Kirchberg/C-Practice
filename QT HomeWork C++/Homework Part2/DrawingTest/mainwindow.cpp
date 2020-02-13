#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
Window::Window()
{
    this->setWindowTitle("Rotate pictures");
    area = new Area( this );
    btn = new QPushButton("Close",this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()),this,SLOT(close()));
};
