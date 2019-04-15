#include "carsyswindow.h"
#include "ui_carsyswindow.h"

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
}

CarsysWindow::~CarsysWindow()
{
    delete ui;
}
