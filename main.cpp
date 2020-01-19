#include "Login.h"
#include <QApplication>
#include "Initialize.h"


int main(int argc, char *argv[])
{

    Initial();
    QApplication a(argc, argv);
    Login w;
    w.show();

    return a.exec();
}






































