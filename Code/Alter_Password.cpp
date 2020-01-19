#include "Alter_Password.h"
#include "ui_alter_password.h"
#include "Passenger.h"
#include <QMessageBox>
extern Passenger passenger;

Alter_Password::Alter_Password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alter_Password)
{
    ui->setupUi(this);
}

Alter_Password::~Alter_Password()
{
    delete ui;
}

void Alter_Password::on_no_clicked()
{
    this->close();
}

void Alter_Password::on_yes_clicked()
{

    QString old = ui->old_password->text();
    QString my_pa = QString::fromLocal8Bit(passenger.getPassword());
    if(old != my_pa){
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("原密码错误！请重新输入！"));
    }
    else{
            QString qp = ui->new_password->text();
            QString qp_a = ui->new_password_again->text();
            if(qp != qp_a){
            QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("两次密码输入不相同！请重新输入！"));
        }
        else{
                if(qp.length()>18){
                    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请输入合法的长度(<=18)"));
                }
                else{
                char* ch;
                QByteArray ba = qp.toLocal8Bit();
                ch = ba.data();
                passenger.setPassword(ch);
                AlterPassenger(passenger);
                QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("修改成功"));
                this->close();
                }
            }
    }
}
