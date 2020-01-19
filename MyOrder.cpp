#include "MyOrder.h"
#include "ui_myorder.h"
#include "MyOrderItem.h"
#include <QString>
#include <QDebug>
#include "Passenger.h"
#include "FlightID.h"

extern Passenger passenger;
MyOrder::MyOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyOrder)
{
    ui->setupUi(this);

    initUI();


}

MyOrder::~MyOrder()
{
    delete ui;
}

void MyOrder::clickedLeftItem(int index)
{
    //ui->listWidget->clear();

}

void MyOrder::initUI()
{
    ui->listWidget->clear();

    FlightID* result;

    result = passenger.get_allFlight();

    for(int i = 0; i < passenger.get_num_allFlight(); i++){
        MyOrderItem* item = new MyOrderItem();
        item->setIndex(i);
        item->startcity->setText(QString::fromLocal8Bit(result[i].getStartPlace()));
        item->endcity->setText(QString::fromLocal8Bit(result[i].getEndPlace()));
        item->flightnum->setText(QString::fromLocal8Bit(result[i].getFlightNumber()));
        item->planenum->setText(QString::fromLocal8Bit(result[i].getPlaneNumer()));

        Time st = result[i].getStartTime();
        Time et = result[i].getEndTime();

        QString qst = (st.getHour()> 9? QString::number(st.getHour()) : ("0"+QString::number(st.getHour())))+":"+(st.getMinute() > 9? QString::number(st.getMinute()) : ("0"+QString::number(st.getMinute())));
        QString qet = (et.getHour()> 9? QString::number(et.getHour()) : ("0"+QString::number(et.getHour())))+":"+(et.getMinute() > 9? QString::number(et.getMinute()) : ("0"+QString::number(et.getMinute())));

        item->starttime->setText(qst);
        item->endtime->setText(qet);

        Date date = result[i].getDepartureDate();
        QDate qqdate(date.getYear(), date.getMonth(), date.getDay());
        QString qdate = QString::number(date.getYear()) + QString::fromLocal8Bit("年") + QString::number(date.getMonth()) + QString::fromLocal8Bit("月") + QString::number(date.getDay()) + QString::fromLocal8Bit("日");

        item->date->setText(qdate);
        int iWeek = qqdate.dayOfWeek();
        switch (iWeek) {
        case 1:
            item->week->setText(QString::fromLocal8Bit("星期一"));
            break;
        case 2:
            item->week->setText(QString::fromLocal8Bit("星期二"));
            break;
        case 3:
            item->week->setText(QString::fromLocal8Bit("星期三"));
            break;
        case 4:
            item->week->setText(QString::fromLocal8Bit("星期四"));
            break;
        case 5:
            item->week->setText(QString::fromLocal8Bit("星期五"));
            break;
        case 6:
            item->week->setText(QString::fromLocal8Bit("星期六"));
            break;
        case 7:
            item->week->setText(QString::fromLocal8Bit("星期日"));
            break;
        default:
            break;
        }

        QString qlevel;
        if(result[i].getLevel() == 1){
            qlevel = QString::fromLocal8Bit("一等座");
        }
        else if(result[i].getLevel() == 2){
            qlevel = QString::fromLocal8Bit("二等座");
        }
        else if(result[i].getLevel() == 3){
            qlevel = QString::fromLocal8Bit("三等座");
        }

        item->level->setText(qlevel);

        QString qseat = QString::number(result[i].getSeat_row()) + QString::fromLocal8Bit("排") + QString::number(result[i].getSeat_colume()) + QString::fromLocal8Bit("列");

        item->seat->setText(qseat);

        QString qprice = QString::number(result[i].getPrice()) + QString::fromLocal8Bit("元");

        item->price->setText(qprice);

        QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(newItem);
        newItem->setSizeHint(QSize(0, 150));
        ui->listWidget->setItemWidget(newItem, item);
        connect(item, SIGNAL(listItemClicked(int)), this, SLOT(clickedLeftItem(int)));

    }
}
