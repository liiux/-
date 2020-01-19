#include "Add_Flight.h"
#include "ui_add_flight.h"
#include "Flight.h"
#include "Write.h"
#include "QMessageBox"

Add_Flight::Add_Flight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_Flight)
{
    ui->setupUi(this);

    initComb();

    QDate today;
    today = QDate::currentDate();
    ui->date->setDate(today);

}

Add_Flight::~Add_Flight()
{
    delete ui;
}

void Add_Flight::on_done_clicked()
{
    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否确定增加该航班？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);

    switch (result) {
    case QMessageBox::Yes:{
        QDate qdate = ui->date->date();

        int y = qdate.year();
        int m = qdate.month();
        int d = qdate.day();

        Date mydate(y, m, d);

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

        QString qsc = ui->startcity->currentText();
        char* sc;
        QByteArray scba = qsc.toLocal8Bit();
        sc = scba.data();

        QString qec = ui->endcity->currentText();
        char* ec;
        QByteArray ecba = qec.toLocal8Bit();
        ec = ecba.data();

        Flight newflight(sc, ec, p, mydate, st, et, fp, sp, tp);


        Write(mydate, newflight);

        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("增加航班成功"));
        break;
    }
    case QMessageBox::No:
        break;
    default:
        break;
    }


}

void Add_Flight::initComb()
{
    for(int i = 0; i < 199; i++){
        ui->startcity->addItem(QString::fromLocal8Bit(AirPorts[i]));
    }

    for(int i = 0; i < 199; i++){
        ui->endcity->addItem(QString::fromLocal8Bit(AirPorts[i]));
    }
}
