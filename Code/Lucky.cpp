#include "Lucky.h"
#include "ui_lucky.h"
#include "FlightID.h"
#include "Passenger.h"
#include "MyOrderItem.h"
#include "Flight.h"
#include "Search.h"
#include <QMessageBox>

extern Passenger passenger;
Lucky::Lucky(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lucky)
{
    ui->setupUi(this);
    initUI();
}

Lucky::~Lucky()
{
    delete ui;
}

void Lucky::clickedLeftItem(int index)
{
    QMessageBox:: StandardButton box= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否确定取消该抢票？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);

    switch (box) {
    case QMessageBox::Yes:{
        FlightID* result;
        result = passenger.get_TicketsAssistant();

        FlightID choice = result[index];

        Flight choiceFlight = SearchByFlightNumber(choice.getDepartureDate(), choice.getFlightNumber());
        int l = choice.getLevel();

        switch (l) {
         case 1:{
            choiceFlight.DeleteFirstQueue(passenger.getID());
            passenger.success_TicketsAssistant(choice);
            AlterPassenger(passenger);
            break;
        }
        case 2:{
            choiceFlight.DeleteSecondQueue(passenger.getID());
            passenger.success_TicketsAssistant(choice);
            AlterPassenger(passenger);
            break;
        }
        case 3:{
            choiceFlight.DeleteThirdQueue(passenger.getID());
            passenger.success_TicketsAssistant(choice);
            AlterPassenger(passenger);
            break;
        }
        default:
            break;
        }
        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("取消抢票成功"));
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

void Lucky::initUI()
{

    passenger.update_TicketsAssistantFlight();

    ui->listWidget->clear();

    FlightID* result;

    result = passenger.get_TicketsAssistant();

    cout<<passenger.get_num_TicketsAssistant();
    for(int i = 0; i < passenger.get_num_TicketsAssistant(); i++){
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


        QString qprice = QString::number(result[i].getPrice()) + QString::fromLocal8Bit("元");

        item->price->setText(qprice);



        QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem(newItem);
        newItem->setSizeHint(QSize(0, 150));
        ui->listWidget->setItemWidget(newItem, item);
        connect(item, SIGNAL(listItemClicked(int)), this, SLOT(clickedLeftItem(int)));
    }
}
