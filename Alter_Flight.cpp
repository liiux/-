#include "Alter_Flight.h"
#include "ui_alter_flight.h"
#include "QDate"
#include "Others.h"
#include "Search.h"
#include <QTime>
#include "Modify.h"
#include <QMessageBox>

Alter_Flight::Alter_Flight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alter_Flight)
{
    ui->setupUi(this);

    QDate today;
    today = QDate::currentDate();
    ui->date->setDate(today);

}

Alter_Flight::~Alter_Flight()
{
    delete ui;
}

void Alter_Flight::on_find_clicked()
{
    QDate qdate = ui->date->date();

    int y = qdate.year();
    int m = qdate.month();
    int d = qdate.day();

    Date mydate(y, m, d);

    QString qf = ui->flightnum->text();
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

        ui->starttime->setTime(qst);
        ui->endtime->setTime(qet);

        ui->startplace->setText(QString::fromLocal8Bit(flight.getStartPlace()));
        ui->endplace->setText(QString::fromLocal8Bit(flight.getEndPlace()));
        ui->planenumber->setText(flight.getPlaneNumber());
        ui->firstprice->setText(QString::number(flight.getFirstPrice()));
        ui->secondprice->setText(QString::number(flight.getSecondPrice()));
        ui->thirdprice->setText(QString::number(flight.getThirdPrice()));
    }
}

void Alter_Flight::on_alter_clicked()
{

    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否确定修改该航班？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);

    switch (result) {
    case QMessageBox::Yes:{
        QDate qdate = ui->date->date();

        int y = qdate.year();
        int m = qdate.month();
        int d = qdate.day();

        Date mydate(y, m, d);

        QString qf = ui->flightnum->text();
        char* f;
        QByteArray fba = qf.toLocal8Bit();
        f = fba.data();

        Flight flight = SearchByFlightNumber(mydate, f);

        char* sc = flight.getStartPlace();
        char* ec = flight.getEndPlace();

        QString qp = ui->planenumber->text();
        char* p;
        QByteArray pba = qp.toLocal8Bit();
        p = pba.data();

        QString qfp = ui->firstprice->text();
        int fp = qfp.toInt();

        QString qsp = ui->secondprice->text();
        int sp = qsp.toInt();

        QString qtp = ui->thirdprice->text();
        int tp = qtp.toInt();

        QTime qst = ui->starttime->time();
        QTime qet = ui->endtime->time();

        Time st(qst.hour(), qst.minute(), qst.second());
        Time et(qet.hour(), qet.minute(), qet.second());

        Flight newflight(sc, ec, p, mydate, st, et, fp, sp, tp);

        ModifyByFlightNumber(mydate, f, newflight);

        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("修改航班成功"));

        break;
    }
    case QMessageBox::No:
        break;
    default:
        break;
    }


}
