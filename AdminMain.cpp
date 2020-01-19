#include "AdminMain.h"
#include "ui_adminmain.h"

AdminMain::AdminMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMain)
{
    ui->setupUi(this);
}

AdminMain::~AdminMain()
{
    delete ui;
}

void AdminMain::on_alter_clicked()
{
    alter_flight = new Alter_Flight(this);
    alter_flight->show();
}

void AdminMain::on_add_clicked()
{
    add_flight = new Add_Flight(this);
    add_flight->show();
}

void AdminMain::on_del_clicked()
{
    delete_flight = new Delete_Flight(this);
    delete_flight->show();
}

void AdminMain::on_query_clicked()
{
    query_flight = new Query_Flight(this);
    query_flight->show();
}

void AdminMain::on_pushButton_clicked()
{
    write_oneday = new Write_Oneday(this);
    write_oneday->show();
}

void AdminMain::on_exit_clicked()
{
    emit this->adminExit();
    this->close();
}
