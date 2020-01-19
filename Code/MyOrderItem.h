#ifndef MYORDERITEM_H
#define MYORDERITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class MyOrderItem : public QWidget
{
    Q_OBJECT
public:
    explicit MyOrderItem(QWidget *parent = nullptr);
    void initUI();
    QLabel* starttime;
    QLabel* endtime;
    QLabel* startcity;
    QLabel* endcity;
    QLabel* date;
    QLabel* price;
    QLabel* level;
    QLabel* seat;
    QLabel* planenum;
    QLabel* flightnum;
    QLabel* week;

    int index;
    void mousePressEvent(QMouseEvent*);
    void setIndex(int ind);
    int getIndex();

signals:
    void listItemClicked(int);
public slots:


};

#endif // MYORDERITEM_H
