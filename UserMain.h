#ifndef USERMAIN_H
#define USERMAIN_H

#include <QMainWindow>
//#include "Login.h"
#include "Alter.h"
#include "Book.h"
#include "MyOrder.h"
#include "Refund.h"
#include "Lucky.h"

namespace Ui {
class UserMain;
}

class UserMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMain(QWidget *parent = 0);
    ~UserMain();

private slots:

    void on_alter_clicked();

    void on_book_clicked();

    void on_myorder_clicked();

    void on_refund_clicked();

    void on_lucky_clicked();

    void on_exit_clicked();

private:
    Ui::UserMain *ui;
    Alter* alter;
    //Login* login;
    Book* book;
    MyOrder* myorder;
    Refund* refund;
    Lucky* lucky;
signals:
    void userExit();
};

#endif // USERMAIN_H
