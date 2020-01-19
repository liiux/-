#include "Delete_Flight.h"
#include "ui_delete_flight.h"
#include "QDate"
#include "Others.h"
#include "Search.h"
#include <QTime>
#include "Delete.h"
#include <QMessageBox>

Delete_Flight::Delete_Flight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Delete_Flight)
{
    ui->setupUi(this);

    QDate today;
    today = QDate::currentDate();
    ui->date->setDate(today);
}

Delete_Flight::~Delete_Flight()
{
    delete ui;
}

void Delete_Flight::on_find_clicked()
{

    ui->startplacelabel->setText(QString::fromLocal8Bit("起飞地点"));
    ui->endplacelabel->setText(QString::fromLocal8Bit("降落地点"));
    ui->starttimelabel->setText(QString::fromLocal8Bit("起飞时间"));
    ui->endtimelabel->setText(QString::fromLocal8Bit("降落时间"));
    ui->planenumberlabel->setText(QString::fromLocal8Bit("飞机号"));
    ui->firstpricelabel->setText(QString::fromLocal8Bit("一等座价格"));
    ui->secondpricelabel->setText(QString::fromLocal8Bit("二等座价格"));
    ui->thirdpricelabel->setText(QString::fromLocal8Bit("三等座价格"));

    QDate qdate = ui->date->date();

    int y = qdate.year();
    int m = qdate.month();
    int d = qdate.day();

    Date mydate(y, m, d);

    QString qf = ui->flightnumber->text();
    char* f;
    QByteArray fba = qf.toLocal8Bit();
    f = fba.data();

    Flight flight = SearchByFlightNumber(mydate, f);
    if(strcmp(flight.getStartPlace(),"NAF")==0){
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("该航班不存在！"));
    }
    else{
        Time st = flight.getStartTime();
        Time et = flight.getEndTime();

        QTime qst(st.getHour(), st.getMinute());
        QTime qet(et.getHour(), et.getMinute());


        ui->starttime->setText((qst.hour()> 9? QString::number(qst.hour()) : ("0"+QString::number(qst.hour())))+":"+(qst.minute() > 9? QString::number(qst.minute()) : ("0"+QString::number(qst.minute()))));
        ui->endtime->setText((qet.hour()> 9? QString::number(qet.hour()) : ("0"+QString::number(qet.hour())))+":"+(qet.minute() > 9? QString::number(qet.minute()) : ("0"+QString::number(qet.minute()))));

        ui->startplace->setText(QString::fromLocal8Bit(flight.getStartPlace()));
        ui->endplace->setText(QString::fromLocal8Bit(flight.getEndPlace()));
        ui->planenumber->setText(flight.getPlaneNumber());
        ui->firstprice->setText(QString::number(flight.getFirstPrice()) + QString::fromLocal8Bit("元"));
        ui->secondprice->setText(QString::number(flight.getSecondPrice()) + QString::fromLocal8Bit("元"));
        ui->thirdprice->setText(QString::number(flight.getThirdPrice()) + QString::fromLocal8Bit("元"));
    }
}

void Delete_Flight::on_done_clicked()
{
    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否确定删除该航班？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    switch (result)
    {
    case QMessageBox::Yes:{
        QDate qdate = ui->date->date();

        int y = qdate.year();
        int m = qdate.month();
        int d = qdate.day();

        Date mydate(y, m, d);

        QString qf = ui->flightnumber->text();
        char* f;
        QByteArray fba = qf.toLocal8Bit();
        f = fba.data();

        DeleteByFlightNumber(mydate, f);

        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("删除航班成功"));

        break;
    }
    case QMessageBox::No:
        break;
    default:
        break;
    }
}
