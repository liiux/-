#ifndef MYORDER_H
#define MYORDER_H

#include <QMainWindow>

namespace Ui {
class MyOrder;
}

class MyOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyOrder(QWidget *parent = 0);
    ~MyOrder();

private:
    Ui::MyOrder *ui;
    void initUI();

private slots:
    void clickedLeftItem(int);

};

#endif // MYORDER_H
