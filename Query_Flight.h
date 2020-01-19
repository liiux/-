#ifndef QUERY_FLIGHT_H
#define QUERY_FLIGHT_H

#include <QMainWindow>

namespace Ui {
class Query_Flight;
}

class Query_Flight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Query_Flight(QWidget *parent = 0);
    ~Query_Flight();

private slots:
    void on_done_clicked();

private:
    Ui::Query_Flight *ui;
    void initUI1();
    void initUI2();
    void initUI3();
    void initUI();
};

#endif // QUERY_FLIGHT_H
