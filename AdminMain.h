#ifndef ADMINMAIN_H
#define ADMINMAIN_H

#include <QMainWindow>
#include "Add_Flight.h"
#include "Alter_Flight.h"
#include "Delete_Flight.h"
#include "Query_Flight.h"
#include "Write_Oneday.h"

namespace Ui {
class AdminMain;
}

class AdminMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMain(QWidget *parent = 0);
    ~AdminMain();

private slots:
    void on_alter_clicked();

    void on_add_clicked();

    void on_del_clicked();

    void on_query_clicked();

    void on_pushButton_clicked();

    void on_exit_clicked();

private:
    Ui::AdminMain *ui;
    Add_Flight* add_flight;
    Alter_Flight* alter_flight;
    Delete_Flight* delete_flight;
    Query_Flight* query_flight;
    Write_Oneday* write_oneday;

signals:
    void adminExit();
};

#endif // ADMINMAIN_H
