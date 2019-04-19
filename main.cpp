#include "carsyswindow.h"
#include "logWindow/logwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarsysWindow w;
    w.show();

    return a.exec();
}
