#ifndef LOGIN_H
#define LOGIN_H

#include "Registe.h"
#include "UserMain.h"
#include <QMainWindow>
#include "Others.h"
#include "Passenger.h"
#include "AdminMain.h"

extern Passenger passenger;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_registe_clicked();

    void on_login_clicked();

    void on_admin_clicked();

    void on_user_clicked();

    void on_checkBox_stateChanged(int arg1);

    void getUserExit();

    void getAdminExit();
private:
    Ui::Login *ui;
    Registe* view_re;
    UserMain* view_lo;
    AdminMain* admin;
};

#endif // LOGIN_H
