#include "Query_Flight.h"
#include "ui_query_flight.h"
#include <Flight.h>
#include <QDate>
#include <Others.h>
#include "Search.h"
#include "Passenger.h"
#include "QueryItem.h"
#include <iostream>
#include <QMessageBox>

Query_Flight::Query_Flight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Query_Flight)
{
    ui->setupUi(this);
    initUI();
}

Query_Flight::~Query_Flight()
{
    delete ui;
}

void Query_Flight::initUI1(){
    ui->listWidget->clear();

    QDate qd = ui->dateEdit->date();
    Date d(qd.year(), qd.month(), qd.day());

    QString qf = ui->flightnumber->text();
    char* f;
    QByteArray fba = qf.toLocal8Bit();
    f = fba.data();

    Flight fff = SearchByFlightNumber(d, f);
    if(strcmp(fff.getStartPlace(),"NAF")==0){
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("该航班不存在！"));
    }
    else{ui->start->setText(QString::fromLocal8Bit(fff.getStartPlace()));
        ui->end->setText(QString::fromLocal8Bit(fff.getEndPlace()));
        ui->to->setText("->");
        for(int i = 0; i < fff.getFirstLength(); i++){
            for(int j = 0; j < fff.getFirstWidth(); j++){
                char* cc = fff.getFirstClass(i, j);
                if(strcmp(cc, "\0") != 0){
                    Passenger ppp = FindPassenger(cc);
                    QueryItem* item = new QueryItem();
                    item->name->setText(QString::fromLocal8Bit(ppp.getName()));
                    item->id->setText(ppp.getID());
                    item->tel->setText(ppp.getPhoneNum());
                    QString qseat = QString::number(i+1) + QString::fromLocal8Bit("排") + QString::number(j+1) + QString::fromLocal8Bit("列");
                    item->seat->setText(qseat);

                    QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
                    ui->listWidget->addItem(newItem);
                    newItem->setSizeHint(QSize(0, 150));
                    ui->listWidget->setItemWidget(newItem, item);

                }
            }
        }}


}

void Query_Flight::initUI2(){
    ui->listWidget->clear();

    QDate qd = ui->dateEdit->date();
    Date d(qd.year(), qd.month(), qd.day());

    QString qf = ui->flightnumber->text();
    char* f;
    QByteArray fba = qf.toLocal8Bit();
    f = fba.data();

    Flight fff = SearchByFlightNumber(d, f);
    if(strcmp(fff.getStartPlace(),"NAF")==0){
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("该航班不存在！"));
    }
    else{
        ui->start->setText(QString::fromLocal8Bit(fff.getStartPlace()));
        ui->end->setText(QString::fromLocal8Bit(fff.getEndPlace()));
        ui->to->setText("->");


        for(int i = 0; i < fff.getSecondLength(); i++){
            for(int j = 0; j < fff.getSecondWidth(); j++){
                char* cc = fff.getSecondClass(i, j);
                if(strcmp(cc, "\0") != 0){
                    Passenger ppp = FindPassenger(cc);

                    QueryItem* item = new QueryItem();
                    item->name->setText(QString::fromLocal8Bit(ppp.getName()));
                    item->id->setText(ppp.getID());
                    item->tel->setText(ppp.getPhoneNum());
                    QString qseat = QString::number(i+1) + QString::fromLocal8Bit("排") + QString::number(j+1) + QString::fromLocal8Bit("列");
                    item->seat->setText(qseat);

                    QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
                    ui->listWidget->addItem(newItem);
                    newItem->setSizeHint(QSize(0, 150));
                    ui->listWidget->setItemWidget(newItem, item);

                }
            }
        }
    }


}

void Query_Flight::initUI3(){
    ui->listWidget->clear();

    QDate qd = ui->dateEdit->date();
    Date d(qd.year(), qd.month(), qd.day());

    QString qf = ui->flightnumber->text();
    char* f;
    QByteArray fba = qf.toLocal8Bit();
    f = fba.data();

    Flight fff = SearchByFlightNumber(d, f);
    if(strcmp(fff.getStartPlace(),"NAF")==0){
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("该航班不存在！"));
    }
    else{
        ui->start->setText(QString::fromLocal8Bit(fff.getStartPlace()));
        ui->end->setText(QString::fromLocal8Bit(fff.getEndPlace()));
        ui->to->setText("->");


        for(int i = 0; i < fff.getThirdLength(); i++){
            for(int j = 0; j < fff.getThirdWidth(); j++){
                char* cc = fff.getThirdClass(i, j);
                if(strcmp(cc, "\0") != 0){
                    Passenger ppp = FindPassenger(cc);

                    QueryItem* item = new QueryItem();
                    item->name->setText(QString::fromLocal8Bit(ppp.getName()));
                    item->id->setText(ppp.getID());
                    item->tel->setText(ppp.getPhoneNum());
                    QString qseat = QString::number(i+1) + QString::fromLocal8Bit("排") + QString::number(j+1) + QString::fromLocal8Bit("列");
                    item->seat->setText(qseat);

                    QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
                    ui->listWidget->addItem(newItem);
                    newItem->setSizeHint(QSize(0, 150));
                    ui->listWidget->setItemWidget(newItem, item);

                }
            }
        }
    }


}

void Query_Flight::initUI(){
    QDate today;
    today = QDate::currentDate();
    ui->dateEdit->setDate(today);
}

void Query_Flight::on_done_clicked()
{
    int i = ui->level->currentIndex();
    switch (i) {
    case 0:{
        initUI1();
        break;
    }
    case 1:{
        initUI2();
        break;
    }
    case 2:{
        initUI3();
        break;
    }
    default:
        break;
    }
}
