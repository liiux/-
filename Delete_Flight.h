#ifndef DELETE_FLIGHT_H
#define DELETE_FLIGHT_H

#include <QMainWindow>

namespace Ui {
class Delete_Flight;
}

class Delete_Flight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Delete_Flight(QWidget *parent = 0);
    ~Delete_Flight();

private slots:
    void on_find_clicked();

    void on_done_clicked();

private:
    Ui::Delete_Flight *ui;
};

#endif // DELETE_FLIGHT_H
