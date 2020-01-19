#include "Refund.h"
#include "ui_refund.h"
#include <QDebug>
#include "FlightID.h"
#include "Passenger.h"
#include"Search.h"
#include <QMessageBox>
#include "MyOrderItem.h"

extern Passenger passenger;

Refund::Refund(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Refund)
{
    ui->setupUi(this);
    initUI();
}

Refund::~Refund()
{
    delete ui;
}


void Refund::clickedLeftItem(int index)
{   
    qDebug() << QString::number(index);
    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否确定退票？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    switch (result) {
    case QMessageBox::Yes:{
        int x=passenger.get_beforeFlight()[index].getSeat_row();
        int y=passenger.get_beforeFlight()[index].getSeat_colume();
        int l = passenger.get_beforeFlight()[index].getLevel();
        char f[20];
        for(int i=0;i<20;i++)
        {
            f[i]=passenger.get_beforeFlight()[index].getFlightNumber()[i];
        }

        Date d=passenger.get_beforeFlight()[index].getDepartureDate();
        FlightID b[30];
        int h=0;
        for(int i=0;i<passenger.get_num_allFlight();i++)
        {
            if(!passenger.get_allFlight()[i].equalTo(passenger.get_beforeFlight()[index]))
                b[h++]=passenger.get_allFlight()[i];
        }
        for(int i=0;i<h;i++)
        {
            passenger.get_allFlight()[i]=b[i];
        }
        passenger.set_num_allFlight(h);
        FlightID a[5];
        int k=0;
        for(int i=0;i<passenger.get_num_beforeFlight();i++)
        {
            if(i!=index)
            {
                a[k++]=passenger.get_beforeFlight()[i];
            }
        }
        for(int i=0;i<k;i++)
        {
            passenger.get_beforeFlight()[i]=a[i];
        }
        passenger.set_num_beforeFlight(k);
        AlterPassenger(passenger);
        Flight F=SearchByFlightNumber(d,f);
        if(l==1){
            F.CancelFirstTicket(x-1,y-1);
        }
        else if(l==2){
            F.CancelSecondTicket(x-1,y-1);
        }
        else if(l==3){
            F.CancelThirdTicket(x-1,y-1);
        }
        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("退票成功"));
        initUI();
        break;
    }
    case QMessageBox::No:{

        break;
    }
    default:
        break;
    }

}

void Refund::initUI()
{

    passenger.update_beforeFlight();

    ui->listWidget->clear();

    FlightID* result;

    result = passenger.get_beforeFlight();

    for(int i = 0; i < passenger.get_num_beforeFlight(); i++){
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
