#include "Login.h"
#include "ui_login.h"
#include "UserMain.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>

Passenger passenger;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->GB->setId(ui->user, 0);
    ui->GB->setId(ui->admin, 1);
    ui->user->setChecked(true);
    ui->account->setPlaceholderText(QString::fromLocal8Bit("身份证号"));
    QIcon i("../noeye.jpg");
    //QIcon i("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\noeye.jpg");
    ui->checkBox->setIcon(i);

}

Login::~Login()
{
    delete ui;
}

void Login::on_registe_clicked()
{

    view_re = new Registe(this);
    view_re->show();
}

void Login::getUserExit()
{
    this->show();
    ui->account->setText("");
    ui->password->setText("");
}

void Login::getAdminExit()
{
    this->show();
    ui->account->setText("");
    ui->password->setText("");
}

void Login::on_login_clicked()
{

    int a = ui->GB->checkedId();
    switch (a) {
    case 0:{
        QString quser = ui->account->text();
        char* user;
        QByteArray userba = quser.toLocal8Bit();
        user = userba.data();

        QString qpass = ui->password->text();
        char* pass;
        QByteArray passba = qpass.toLocal8Bit();
        pass = passba.data();

        if(quser.length() != 18){
            QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请输入合法的身份证号码！"));
        }
        else{
            Passenger temp;

            temp = FindPassenger(user);


            if(strcmp(temp.getPassword(), pass) != 0){
                QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("用户名或密码错误"));
            }
            else{
                passenger = temp;
                this->hide();
                view_lo = new UserMain(this);
                connect(view_lo, SIGNAL(userExit()), this, SLOT(getUserExit()));
                view_lo->show();
            }
        }
        break;
    }
    case 1:{
        QString qadm = ui->account->text();
        char* adm;
        QByteArray admba = qadm.toLocal8Bit();
        adm = admba.data();

        QString qpass = ui->password->text();
        char* pass;
        QByteArray passba = qpass.toLocal8Bit();
        pass = passba.data();


        Passenger p1, p2, p3;
        const char* pc1 = "445221199909051636";
        const char* pc2 = "142431199902187514";
        const char* pc3 = "440509199811121218";
        p1 = FindPassenger(pc1);
        p2 = FindPassenger(pc2);
        p3 = FindPassenger(pc3);

        if(((strcmp(p1.getID(), adm) == 0) && (strcmp(p1.getPassword(), pass) == 0)) || ((strcmp(p2.getID(), adm) == 0) && (strcmp(p2.getPassword(), pass) == 0)) || ((strcmp(p3.getID(), adm) == 0) && (strcmp(p3.getPassword(), pass) == 0))){
            this->hide();
            admin = new AdminMain(this);
            connect(admin, SIGNAL(adminExit()), this, SLOT(getAdminExit()));
            admin->show();
        }
        else{
            QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("账号或密码错误"));
        }



        break;
    }
    default:
        break;
    }

}

void Login::on_admin_clicked()
{
    ui->account->setPlaceholderText(QString::fromLocal8Bit("管理员账号"));
}


void Login::on_user_clicked()
{
    ui->account->setPlaceholderText(QString::fromLocal8Bit("身份证号"));
}

void Login::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->password->setEchoMode(QLineEdit::Password);
        QIcon i("../noeye.jpg");
        //QIcon i("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\noeye.jpg");
        ui->checkBox->setIcon(i);
    }
    else{
        ui->password->setEchoMode(QLineEdit::Normal);
        QIcon i("../eye.jpg");
        //QIcon i("C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\eye.jpg");
        ui->checkBox->setIcon(i);
    }
}
