#include "Item.h"
#include <QGridLayout>
#include <QLabel>
#include <QFont>

Item::Item(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void Item::initUI()
{
    QFont font1;
    font1.setFamily("宋体");
    font1.setPointSize(14);
    QFont font2;
    font2.setPointSize(10);
    QFont font3;
    font3.setFamily("宋体");
    font3.setPointSize(20);

    QGridLayout* layout = new QGridLayout(this);

    QLabel* to;
    layout->addWidget(starttime = new QLabel(), 1, 1);
    layout->addWidget(to = new QLabel("->"), 2, 2);
    layout->addWidget(endtime = new QLabel(), 1, 3);
    layout->addWidget(startcity = new QLabel(), 2, 1);
    layout->addWidget(endcity = new QLabel(), 2, 3);
    layout->addWidget(flightnum = new QLabel(), 3, 1);
    layout->addWidget(planenum = new QLabel(), 3, 3);
    startcity->setFont(font1);
    endcity->setFont(font1);
    starttime->setFont(font1);
    endtime->setFont(font1);
    flightnum->setFont(font2);
    planenum->setFont(font2);
    to->setFont(font3);

}


void Item::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit this->listItemClicked(index);
    }
}

void Item::setIndex(int ind)
{
    this->index = ind;
}

int Item::getIndex()
{
    return index;
}
