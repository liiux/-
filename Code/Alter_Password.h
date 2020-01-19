#ifndef ALTER_PASSWORD_H
#define ALTER_PASSWORD_H

#include <QMainWindow>

namespace Ui {
class Alter_Password;
}

class Alter_Password : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alter_Password(QWidget *parent = 0);
    ~Alter_Password();

private slots:
    void on_no_clicked();

    void on_yes_clicked();

private:
    Ui::Alter_Password *ui;
};

#endif // ALTER_PASSWORD_H
