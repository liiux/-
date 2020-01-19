#ifndef ALTER_H
#define ALTER_H

#include <QMainWindow>
#include "Alter_Password.h"

namespace Ui {
class Alter;
}

class Alter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alter(QWidget *parent = 0);
    ~Alter();
    Alter_Password* alter_password;

private slots:
    void on_alter_password_clicked();

    void on_alter_tel_clicked();

private:
    Ui::Alter *ui;
};

#endif // ALTER_H
