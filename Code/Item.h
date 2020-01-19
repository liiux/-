#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

class Item : public QWidget
{
    Q_OBJECT
public:
    explicit Item(QWidget *parent = nullptr);
    void initUI();
    QLabel* startcity;
    QLabel* endcity;
    QLabel* starttime;
    QLabel* endtime;
    QLabel* flightnum;
    QLabel* planenum;
    //QPushButton* done;
    int index;
    void mousePressEvent(QMouseEvent*);
    void setIndex(int ind);
    int getIndex();

signals:
    void listItemClicked(int);
public slots:

};

#endif // ITEM_H
