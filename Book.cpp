#include "Book.h"
#include "ui_book.h"
#include <QDate>
#include "Item.h"
#include <QDebug>
#include <queue>
#include <QMessageBox>
#include "Others.h"


Flight flight;
Book::Book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);

    initComb();

    QDate today;
    today = QDate::currentDate();
    ui->date->setDate(today);

    int i = today.dayOfWeek();
    switch (i) {
    case 1:
        ui->week->setText(QString::fromLocal8Bit("星期一"));
        break;
    case 2:
        ui->week->setText(QString::fromLocal8Bit("星期二"));
        break;
    case 3:
        ui->week->setText(QString::fromLocal8Bit("星期三"));
        break;
    case 4:
        ui->week->setText(QString::fromLocal8Bit("星期四"));
        break;
    case 5:
        ui->week->setText(QString::fromLocal8Bit("星期五"));
        break;
    case 6:
        ui->week->setText(QString::fromLocal8Bit("星期六"));
        break;
    case 7:
        ui->week->setText(QString::fromLocal8Bit("星期日"));
        break;
    default:
        break;
    }



}

Book::~Book()
{
    delete ui;
}

void Book::clickedLeftItem(int index)
{
    qDebug() << QString::number(index);
    vector<Flight> myresult;



    QDate qdate = ui->date->date();
    int d = qdate.day();
    int m = qdate.month();
    int y = qdate.year();
    Date date(y, m, d);

    char* start;
    char* end;

    QString qstart;
    QString qend;

    qstart = ui->start->currentText();
    qend = ui->end->currentText();

    QByteArray bastart = qstart.toLocal8Bit();
    start = bastart.data();
    
    QByteArray baend = qend.toLocal8Bit();
    end = baend.data();

    myresult = Search(date, start, end);

    flight = myresult[index];

    Time tt = flight.getStartTime();
    Date dd = flight.getDepartureDate();

    QTime qtt(tt.getHour(), tt.getMinute(), tt.getSecond());
    QDate qdd(dd.getYear(), dd.getMonth(), dd.getDay());

    QDate currd = QDate::currentDate();
    QTime currt = QTime::currentTime();

    int flag = 0;

    if(qdd < currd){
        flag = 1;
    }
    else if(qdd == currd){
        if(qtt < currt){
            flag = 1;
        }
    }

    if(flag == 1){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("该航班已经起飞"));
    }
    else{
        bookorder = new BookOrder(this);
        bookorder->show();
    }

}

void Book::initComb()
{
    for(int i = 0; i < 199; i++){
        ui->start->addItem(QString::fromLocal8Bit(AirPorts[i]));
    }

    for(int i = 0; i < 199; i++){
        ui->end->addItem(QString::fromLocal8Bit(AirPorts[i]));
    }
}

void Book::on_change_clicked()
{
    int temp1 = ui->start->currentIndex();
    int temp2 = ui->end->currentIndex();
    ui->start->setCurrentIndex(temp2);
    ui->end->setCurrentIndex(temp1);
}

void Book::on_find_clicked()
{
    if(ui->start->currentText() == ui->end->currentText()){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("起点和终点不能一样"));
    }
    else{
        ui->listWidget->clear();

        vector<Flight> myresult;


        QDate qdate = ui->date->date();
        int d = qdate.day();
        int m = qdate.month();
        int y = qdate.year();
        Date date(y, m, d);

        char* start;
        char* end;

        QString qstart;
        QString qend;

        qstart = ui->start->currentText();
        qend = ui->end->currentText();

        QByteArray bastart = qstart.toLocal8Bit();
        start = bastart.data();

        QByteArray baend = qend.toLocal8Bit();
        end = baend.data();

        myresult = Search(date, start, end);

        int len = myresult.size();

        if(len == 0){
            QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("该航班不存在！"));
        }
        else{
            for(int i = 0; i < len; i++){
                Item *item = new Item();
                item->setIndex(i);
                Flight f;
                f = myresult[i];

                Time st = f.getStartTime();
                Time et = f.getEndTime();

                QString qst = (st.getHour()> 9? QString::number(st.getHour()) : ("0"+QString::number(st.getHour())))+":"+(st.getMinute() > 9? QString::number(st.getMinute()) : ("0"+QString::number(st.getMinute())));
                QString qet = (et.getHour()> 9? QString::number(et.getHour()) : ("0"+QString::number(et.getHour())))+":"+(et.getMinute() > 9? QString::number(et.getMinute()) : ("0"+QString::number(et.getMinute())));


                item->startcity->setText(QString::fromLocal8Bit(f.getStartPlace()));
                item->endcity->setText(QString::fromLocal8Bit(f.getEndPlace()));
                item->flightnum->setText(QString::fromLocal8Bit(f.getFlightNumber()));
                item->planenum->setText(QString::fromLocal8Bit(f.getPlaneNumber()));
                item->starttime->setText(qst);
                item->endtime->setText(qet);

                QListWidgetItem *newItem =new QListWidgetItem(ui->listWidget);
                ui->listWidget->addItem(newItem);
                newItem->setSizeHint(QSize(0, 150));
                ui->listWidget->setItemWidget(newItem, item);
                connect(item, SIGNAL(listItemClicked(int)), this, SLOT(clickedLeftItem(int)));

            }
        }

    }

}


void Book::on_date_dateChanged(const QDate &date)
{
    int i = date.dayOfWeek();
    switch (i) {
    case 1:
        ui->week->setText(QString::fromLocal8Bit("星期一"));
        break;
    case 2:
        ui->week->setText(QString::fromLocal8Bit("星期二"));
        break;
    case 3:
        ui->week->setText(QString::fromLocal8Bit("星期三"));
        break;
    case 4:
        ui->week->setText(QString::fromLocal8Bit("星期四"));
        break;
    case 5:
        ui->week->setText(QString::fromLocal8Bit("星期五"));
        break;
    case 6:
        ui->week->setText(QString::fromLocal8Bit("星期六"));
        break;
    case 7:
        ui->week->setText(QString::fromLocal8Bit("星期日"));
        break;
    default:
        break;
    }
}
