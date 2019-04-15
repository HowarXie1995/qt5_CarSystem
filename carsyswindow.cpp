#include "carsyswindow.h"
#include "ui_carsyswindow.h"

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
    //setParent(0);
    //showFullScreen();
    timer = new QTimer(this);

    if(SERIAL_OPEN_FAIL == moddb.error)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_erro);
        ui->label_erro->setText("串口打开失败");
        connect(timer, SIGNAL(timeout()), this, SLOT(reinitSerial()));
        timer->start(1000);

    }else//串口打开成功后
    {

    }


}

CarsysWindow::~CarsysWindow()
{
    delete myprocess;
    delete ui;
}

void CarsysWindow::getUserInf(UserData infor)
{
   userInf = infor;
   //获得用户数据
}
void CarsysWindow::reinitSerial()
{
   moddb.initSerail();
}

