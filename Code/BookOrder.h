#ifndef BOOKORDER_H
#define BOOKORDER_H

#include <QMainWindow>

namespace Ui {
class BookOrder;
}

class BookOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookOrder(QWidget *parent = 0);
    ~BookOrder();
    void initUI();

private slots:
    void on_done_clicked();

    void on_level_currentIndexChanged(int index);

private:
    Ui::BookOrder *ui;
};

#endif // BOOKORDER_H
