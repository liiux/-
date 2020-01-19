#include "MyOrderItem.h"
#include <QGridLayout>
#include <QFont>

MyOrderItem::MyOrderItem(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void MyOrderItem::initUI()
{
    QFont font1;
    font1.setFamily("宋体");
    font1.setPointSize(14);
    QFont font2;
    font2.setFamily("宋体");
    font2.setPixelSize(10);
    QFont font3;
    font3.setFamily("宋体");
    font3.setPointSize(20);

    QGridLayout* layout = new QGridLayout(this);

    QLabel* to1;
    layout->addWidget(startcity = new QLabel(), 0, 0);
    layout->addWidget(to1 = new QLabel("->"), 0, 1);
    layout->addWidget(endcity = new QLabel(), 0, 2);
    layout->addWidget(date = new QLabel(), 0, 3);
    layout->addWidget(seat = new QLabel(), 1, 3);
    layout->addWidget(starttime = new QLabel(), 1, 0);
    QLabel* to2;
    layout->addWidget(to2 = new QLabel(QString::fromLocal8Bit("——")), 1, 1);
    layout->addWidget(endtime = new QLabel(), 1, 2);
    layout->addWidget(week = new QLabel(), 0, 5);
    layout->addWidget(level = new QLabel(), 1, 5);
    layout->addWidget(price = new QLabel(), 2, 5);
    layout->addWidget(planenum = new QLabel(), 2, 1);
    layout->addWidget(flightnum = new QLabel(), 2, 0);

    startcity->setFont(font1);
    to1->setFont(font3);
    endcity->setFont(font1);
}

void MyOrderItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit this->listItemClicked(index);
    }
}

void MyOrderItem::setIndex(int ind)
{
    this->index = ind;
}

int MyOrderItem::getIndex()
{
    return index;
}
