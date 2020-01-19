#ifndef LUCKY_H
#define LUCKY_H

#include <QMainWindow>

namespace Ui {
class Lucky;
}

class Lucky : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lucky(QWidget *parent = 0);
    ~Lucky();

private:
    Ui::Lucky *ui;
    void initUI();

private slots:
    void clickedLeftItem(int);
};

#endif // LUCKY_H
