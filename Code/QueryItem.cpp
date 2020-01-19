#include "QueryItem.h"
#include <QGridLayout>
#include <QFont>

QueryItem::QueryItem(QWidget *parent) : QWidget(parent)
{
    init();
}

void QueryItem::init(){
    QFont font;
    font.setPointSize(15);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(name = new QLabel(), 0, 0);
    layout->addWidget(id = new QLabel(), 0, 1);
    layout->addWidget(tel = new QLabel(), 1, 0);
    layout->addWidget(seat = new QLabel(), 1, 1);

    name->setFont(font);
}
