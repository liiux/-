#ifndef QUERYITEM_H
#define QUERYITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class QueryItem : public QWidget
{
    Q_OBJECT
public:
    explicit QueryItem(QWidget *parent = nullptr);
    void init();
    QLabel* name;
    QLabel* id;
    QLabel* tel;
    QLabel* seat;


signals:

public slots:
};

#endif // QUERYITEM_H
