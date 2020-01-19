#ifndef WRITE_ONEDAY_H
#define WRITE_ONEDAY_H

#include <QMainWindow>

namespace Ui {
class Write_Oneday;
}

class Write_Oneday : public QMainWindow
{
    Q_OBJECT

public:
    explicit Write_Oneday(QWidget *parent = 0);
    ~Write_Oneday();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Write_Oneday *ui;
};

#endif // WRITE_ONEDAY_H
