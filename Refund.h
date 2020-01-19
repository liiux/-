#ifndef REFUND_H
#define REFUND_H

#include <QMainWindow>
namespace Ui {
class Refund;
}

class Refund : public QMainWindow
{
    Q_OBJECT

public:
    explicit Refund(QWidget *parent = 0);
    ~Refund();

private:
    Ui::Refund *ui;
    void initUI();

private slots:
    void clickedLeftItem(int);

};

#endif // REFUND_H
