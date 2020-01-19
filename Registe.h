#ifndef REGISTE_H
#define REGISTE_H

#include <QMainWindow>

namespace Ui {
class Registe;
}

class Registe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registe(QWidget *parent = 0);
    ~Registe();

private slots:
    void on_no_clicked();

    void on_yes_clicked();

private:
    Ui::Registe *ui;
};

#endif // REGISTE_H
