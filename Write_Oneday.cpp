#include "Write_Oneday.h"
#include "ui_write_oneday.h"
#include <QDate>
#include <Others.h>
#include <Write.h>
#include <QMessageBox>

Write_Oneday::Write_Oneday(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Write_Oneday)
{
    ui->setupUi(this);
    QDate today;
    today = QDate::currentDate();
    ui->dateEdit->setDate(today);
}

Write_Oneday::~Write_Oneday()
{
    delete ui;
}

void Write_Oneday::on_pushButton_clicked()
{
    //ui->progressBar->reset();

    QDate qd = ui->dateEdit->date();

    Date date(qd.year(), qd.month(), qd.day());

    int year = date.getYear();
    int month = date.getMonth();
    int day = date.getDay();
    char Y[10];
    char M[5];
    char D[5];
    _itoa_s(year, Y, 10);
    _itoa_s(month, M, 10);
    _itoa_s(day, D, 10);
    char address[100] = "../航班信息/";
    //char address[100] = "E:\\QT\\qt\\Projects\\MY\\航班信息\\";
    //char address[100] = "C:\\Users\\14376\\Desktop\\课程\\数据结构大作业\\航班信息\\";
    strcat_s(address, Y);
    strcat_s(address, "-");
    if (month < 10)strcat_s(address, "0");
    strcat_s(address, M);
    strcat_s(address, "-");
    if (day < 10)strcat_s(address, "0");
    strcat_s(address, D);
    strcat_s(address, ".dat");
    fstream in;
    in.open(address);
    if (!in.fail()) {
        QMessageBox:: StandardButton result= QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("已存在该天的航班的信息，是否覆盖？"), QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
        switch (result) {
        case QMessageBox::Yes:{
            remove(address);
            WriteTT(date, ui->progressBar);
            QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("航班信息已生成！"));
            break;
            }
        default:
            break;
        }
    }
    else{
        WriteTT(date, ui->progressBar);
        QMessageBox::warning(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("航班信息已生成！"));
    }
}
