#include "carsyswindow.h"
#include "ui_carsyswindow.h"

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
    //setParent(0);
    //showFullScreen();

    if(SERIAL_OPEN_FAIL == moddb.error)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_erro);
        ui->label_erro->setText("串口打开失败");
        //moddb.initSerail(2000);
    }else//串口打开成功后
    {

    }


}

CarsysWindow::~CarsysWindow()
{
    delete ui;
}

void CarsysWindow::getUserInf(UserData infor)
{
   userInf = infor;
   //获得用户数据
}

