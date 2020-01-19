#ifndef ALTER_FLIGHT_H
#define ALTER_FLIGHT_H

#include <QMainWindow>

namespace Ui {
class Alter_Flight;
}

class Alter_Flight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alter_Flight(QWidget *parent = 0);
    ~Alter_Flight();

private slots:
    void on_find_clicked();

    void on_alter_clicked();

private:
    Ui::Alter_Flight *ui;
};

#endif // ALTER_FLIGHT_H
