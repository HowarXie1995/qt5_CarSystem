#include "carsyswindow.h"
#include "ui_carsyswindow.h"

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
    //setParent(0);
    //showFullScreen();
    if(SERIAL_OPEN_FAIL == moddb->error)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_erro);
        ui->label_erro->setText("串口打开失败");
    }else
    {
        ui->stackedWidget->setCurrentWidget(ui->page_erro);
        ui->label_erro->setText("串口打开成功");
    }

}

CarsysWindow::~CarsysWindow()
{
    free(moddb);
    delete ui;
}

void CarsysWindow::getUserInf(UserData infor)
{
   userInf = infor;
   //获得用户数据
}

void CarsysWindow::initModBusHandler()
{
   moddb = new modbusHandle;
}
