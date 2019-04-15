#ifndef CARSYSWINDOW_H
#define CARSYSWINDOW_H

#include <QMainWindow>

namespace Ui {
class CarsysWindow;
}

class CarsysWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarsysWindow(QWidget *parent = 0);
    ~CarsysWindow();

private:
    Ui::CarsysWindow *ui;
};

#endif // CARSYSWINDOW_H
