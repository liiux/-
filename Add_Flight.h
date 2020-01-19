#ifndef ADD_FLIGHT_H
#define ADD_FLIGHT_H

#include <QMainWindow>
#include "Others.h"

namespace Ui {
class Add_Flight;
}

class Add_Flight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_Flight(QWidget *parent = 0);
    ~Add_Flight();

private slots:
    void on_done_clicked();
    void initComb();

private:
    Ui::Add_Flight *ui;
};

#endif // ADD_FLIGHT_H
