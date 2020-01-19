#include "UserMain.h"
#include "ui_usermain.h"
#include "Login.h"
#include "Book.h"
#include "MyOrder.h"

extern Passenger passenger;

UserMain::UserMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMain)
{
    ui->setupUi(this);
    ui->name->setText(QString::fromLocal8Bit(passenger.getName()));
    ui->label->setText(passenger.getID());
}

UserMain::~UserMain()
{
    delete ui;
}


void UserMain::on_alter_clicked()
{
    alter = new Alter(this);
    alter->show();
}

void UserMain::on_book_clicked()
{
    book = new Book(this);
    book->show();
}

void UserMain::on_myorder_clicked()
{
    myorder = new MyOrder(this);
    myorder->show();
}

void UserMain::on_refund_clicked()
{
    refund = new Refund(this);
    refund->show();
}

void UserMain::on_lucky_clicked()
{
    lucky = new Lucky(this);
    lucky->show();
}

void UserMain::on_exit_clicked()
{
    emit this->userExit();
    this->close();
}
