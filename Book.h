#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>
#include "background.h"
#include "Flight.h"
#include "Others.h"
#include "Search.h"
#include "Flight.h"
#include "BookOrder.h"

extern int BOOKNUMBER;
extern Flight flight;

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = 0);
    ~Book();

private:
    Ui::Book *ui;
    void initComb();
    BookOrder* bookorder;

private slots:
    void clickedLeftItem(int);
    void on_change_clicked();
    void on_find_clicked();
    void on_date_dateChanged(const QDate &date);
};

#endif // BOOK_H
