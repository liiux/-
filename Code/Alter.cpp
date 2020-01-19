#include "Alter.h"
#include "ui_alter.h"
#include "background.h"
#include "Flight.h"
#include "FlightID.h"
#include "index.h"
#include "Initialize.h"
#include "Modify.h"
#include "Others.h"
#include "Search.h"
#include "Write.h"
#include "Passenger.h"
#include <QDebug>
#include <QMessageBox>
extern Passenger passenger;

Alter::Alter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alter)
{
    ui->setupUi(this);
    ui->name->setText(QString::fromLocal8Bit(passenger.getName()));
    ui->id->setText(QString::fromLocal8Bit(passenger.getID()));
    ui->tel->setText(passenger.getPhoneNum());
}

Alter::~Alter()
{
    delete ui;
}

void Alter::on_alter_password_clicked()
{
    alter_password = new Alter_Password(this);
    alter_password->show();
}

void Alter::on_alter_tel_clicked()
{
    QString qtel = ui->tel->text();
    if(qtel.length()>18){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请输入合法的长度(<=18)"));
    }
    else{

    char* ch;
    QByteArray ba = qtel.toLocal8Bit();
    ch = ba.data();


    passenger.setPhoneNum(ch);


    AlterPassenger(passenger);

    QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("修改成功"));
    }

}
