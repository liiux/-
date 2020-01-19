#include "BookOrder.h"
#include "ui_bookorder.h"
#include "Passenger.h"
#include "Search.h"
#include "Flight.h"
#include "FlightID.h"
#include <QDebug>
#include"Modify.h"
#include"Others.h"
#include <QMessageBox>
extern Passenger passenger;
extern Flight flight;
BookOrder::BookOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookOrder)
{
    ui->setupUi(this);
    initUI();
}

BookOrder::~BookOrder()
{
    delete ui;
}

void BookOrder::on_done_clicked()
{
    qDebug() << flight.getFlightNumber();
    passenger.update_beforeFlight();
    passenger.update_TicketsAssistantFlight();
    Seat seat;
    int l = ui->level->currentIndex();
    if(flight.ifBookAgain(passenger.getID())){
        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您已订购此航班，不可重复订票"));
    }
    else{
        if(l == 0){
            if(flight.ifFirstFull()){
                if(!flight.CanPushFirst()){
                    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("对不起，一等座座位已满！"));
                }
                else{
                    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("一等座座位已满，是否需要为您提供抢票服务？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
                                switch (result) {
                                case QMessageBox::Yes:{
                                    if(passenger.get_num_TicketsAssistant() < 10){
                                        FlightID* fff = passenger.get_TicketsAssistant();
                                        FlightID ffid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, 0, 0, flight.getFirstPrice());
                                        fff[passenger.get_num_TicketsAssistant()]=ffid;
                                        passenger.set_TicketsAssistant(fff);
                                        cout<<passenger.get_TicketsAssistant()[passenger.get_num_TicketsAssistant()].getDepartureDate().getDay()<<endl;
                                        passenger.set_num_TicketsAssistant(passenger.get_num_TicketsAssistant()+1);
                                        flight.pushFirstQueue(passenger.getID());
                                        int size=flight.getFirstQueueNum();
                                        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("已帮您加入抢票队列"));                                    }
                                    else{
                                        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的抢票数量已达上限，无法再帮您抢票"));
                                    }

                                    break;
                                }
                                case QMessageBox::No:{

                                    break;
                                }
                                default:
                                    break;
                                }
                }

            }
            else{
                if(passenger.ifCanBook()){
                    seat=flight.addFirstPassager(passenger.getID());
                    FlightID fid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, seat.getX()+1, seat.getY()+1, flight.getFirstPrice());
                    passenger.BookTicket(fid);
                    QString ss = QString::fromLocal8Bit("订票成功，您的座位号是：") + QString::number(seat.getX()+1) + QString::fromLocal8Bit("排") + QString::number(seat.getY()+1) + QString::fromLocal8Bit("列");
                    QMessageBox::warning(this, QString::fromLocal8Bit("成功"), ss);
                }
                else{
                    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("一人最多可预定5班未起飞航班。请待其他航班起飞后再进行预定"));
                }
            }
        }
        else if(l == 1){
            if(flight.ifSecondFull()){
                if(!flight.CanPushSecond()){
                    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("对不起，二等座座位已满！"));
                }
                else{
                    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("二等座座位已满，是否需要为您提供抢票服务？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
                                switch (result) {
                                case QMessageBox::Yes:{

                                    if(passenger.get_num_TicketsAssistant() < 10){
                                        FlightID* fff = passenger.get_TicketsAssistant();
                                        FlightID ffid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, 0, 0, flight.getFirstPrice());
                                        fff[passenger.get_num_TicketsAssistant()]=ffid;
                                        passenger.set_TicketsAssistant(fff);
                                        passenger.set_num_TicketsAssistant(passenger.get_num_TicketsAssistant()+1);
                                        flight.pushSecondQueue(passenger.getID());
                                    }
                                    else{
                                        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的抢票数量已达上限，无法再帮您抢票"));
                                    }

                                    break;
                                }
                                case QMessageBox::No:{

                                    break;
                                }
                                default:
                                    break;
                                }
                }

            }
                else{
                    if(passenger.ifCanBook()){
                        seat=flight.addSecondPassager(passenger.getID());
                        FlightID fid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, seat.getX()+1, seat.getY()+1, flight.getFirstPrice());
                        passenger.BookTicket(fid);
                        QString ss = QString::fromLocal8Bit("订票成功，您的座位号是：") + QString::number(seat.getX()+1) + QString::fromLocal8Bit("排") + QString::number(seat.getY()+1) + QString::fromLocal8Bit("列");
                        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), ss);
                    }
                    else{
                        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("一人最多可预定5班未起飞航班。请待其他航班起飞后再进行预定"));
                    }
                }

        }
        else if(l == 2){
            if(flight.ifThirdFull()){
                if(!flight.CanPushThird()){
                    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("对不起，三等座座位已满！"));
                }
                else{
                    QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("三等座座位已满，是否需要为您提供抢票服务？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
                                switch (result) {
                                case QMessageBox::Yes:{

                                    if(passenger.get_num_TicketsAssistant() < 10){
                                        FlightID* fff = passenger.get_TicketsAssistant();
                                        FlightID ffid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, 0, 0, flight.getFirstPrice());
                                        fff[passenger.get_num_TicketsAssistant()]=ffid;
                                        passenger.set_TicketsAssistant(fff);
                                        passenger.set_num_TicketsAssistant(passenger.get_num_TicketsAssistant()+1);
                                        flight.pushThirdQueue(passenger.getID());
                                    }
                                    else{
                                        QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("您的抢票数量已达上限，无法再帮您抢票"));
                                    }

                                    break;
                                }
                                case QMessageBox::No:{

                                    break;
                                }
                                default:
                                    break;
                                }
                }

            }
            else{
                if(passenger.ifCanBook()){
                    seat=flight.addThirdPassager(passenger.getID());
                    FlightID fid(flight.getStartPlace(), flight.getEndPlace(), flight.getFlightNumber(), flight.getPlaneNumber(), flight.getDepartureDate(), flight.getStartTime(), flight.getEndTime(), 1, seat.getX()+1, seat.getY()+1, flight.getFirstPrice());
                    passenger.BookTicket(fid);
                    QString ss = QString::fromLocal8Bit("订票成功，您的座位号是：") + QString::number(seat.getX()+1) + QString::fromLocal8Bit("排") + QString::number(seat.getY()+1) + QString::fromLocal8Bit("列");
                    QMessageBox::warning(this, QString::fromLocal8Bit("成功"), ss);
                }
                else{
                    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("一人最多可预定5班未起飞航班。请待其他航班起飞后再进行预定"));
                }
            }
        }
        ModifyByFlightNumber2(flight.getDepartureDate(), flight.getFlightNumber(), flight);
        AlterPassenger(passenger);
        this->close();
    }

}

void BookOrder::initUI()
{
    ui->startcity->setText(QString::fromLocal8Bit(flight.getStartPlace()));
    ui->endcity->setText(QString::fromLocal8Bit(flight.getEndPlace()));
    Time st = flight.getStartTime();
    Time et = flight.getEndTime();
    QString qst = (st.getHour()> 9? QString::number(st.getHour()) : ("0"+QString::number(st.getHour())))+":"+(st.getMinute() > 9? QString::number(st.getMinute()) : ("0"+QString::number(st.getMinute())));
    QString qet = (et.getHour()> 9? QString::number(et.getHour()) : ("0"+QString::number(et.getHour())))+":"+(et.getMinute() > 9? QString::number(et.getMinute()) : ("0"+QString::number(et.getMinute())));
    ui->starttime->setText(qst);
    ui->endtime->setText(qet);
    ui->price->setText(QString::number(flight.getFirstPrice()) + QString::fromLocal8Bit("元"));
    ui->num->setText((QString::fromLocal8Bit("剩"))+QString::number(flight.getFirstRemain()));
}

void BookOrder::on_level_currentIndexChanged(int index)
{
    if(index == 0){
        ui->price->setText(QString::number(flight.getFirstPrice()) + QString::fromLocal8Bit("元"));
        ui->num->setText((QString::fromLocal8Bit("剩"))+QString::number(flight.getFirstRemain()));
    }
    else if(index == 1){
        ui->price->setText(QString::number(flight.getSecondPrice()) + QString::fromLocal8Bit("元"));
        ui->num->setText((QString::fromLocal8Bit("剩"))+QString::number(flight.getSecondRemain()));
    }
    else if(index == 2){
        ui->price->setText(QString::number(flight.getThirdPrice()) + QString::fromLocal8Bit("元"));
        ui->num->setText((QString::fromLocal8Bit("剩"))+QString::number(flight.getThirdRemain()));
    }
}
