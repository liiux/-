#include "Registe.h"
#include "ui_registe.h"
#include <QMessageBox>
#include "Passenger.h"
#include "Others.h"

Registe::Registe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registe)
{
    ui->setupUi(this);
}

Registe::~Registe()
{
    delete ui;
}

void Registe::on_no_clicked()
{
    this->close();
}

void Registe::on_yes_clicked()
{
    QString qn = ui->name->text();
    QString qid = ui->id->text();
    QString qt = ui->tel->text();
    QString qp = ui->password->text();
    QString qp_a = ui->password_again->text();
    if(qid.length() != 18){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请输入合法的身份证号码"));
    }
    else if(qn.length()>18||qid.length()>18||qt.length()>18||qp.length()>18||qp_a.length()>18){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请输入合法的长度(<=18)"));
    }
    else{
    if(qp != qp_a){
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("两次密码输入不相同！请重新输入！"));
    }
    else{
        char* n;
        QByteArray nba = qn.toLocal8Bit();
        n = nba.data();

        char* id;
        QByteArray idba = qid.toLocal8Bit();
        id = idba.data();


        char* t;
        QByteArray tba = qt.toLocal8Bit();
        t = tba.data();

        char* p;
        QByteArray pba = qp.toLocal8Bit();
        p = pba.data();

        if(ifRight(id)){
            Passenger pass = Passenger(n, id, t, p);

            int r = InsertPassenger(pass);

            if(r == 1){
                QMessageBox::warning(this, QString::fromLocal8Bit("警告1"), QString::fromLocal8Bit("注册失败，请联系管理员更新数据库"));
            }
            else if(r == 2){
                QMessageBox::warning(this, QString::fromLocal8Bit("警告2"), QString::fromLocal8Bit("该身份证号已被注册"));
            }
            else if(r == 3){
                QMessageBox::warning(this, QString::fromLocal8Bit("警告3"), QString::fromLocal8Bit("注册失败，请联系管理员更新数据库"));
            }
            else{
                Passenger p;
                int total = p.show_now_num_of_passenger();
                QString xxx = QString::fromLocal8Bit("注册成功，您是第") + QString::number(total) + QString::fromLocal8Bit("位注册的用户");
                QMessageBox::warning(this, QString::fromLocal8Bit("恭喜"), xxx);
                this->close();
            }
        }
        else{
            QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("请输入合法的身份证号码"));
        }


    }
    }
}
