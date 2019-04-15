#include "carsyswindow.h"
#include "ui_carsyswindow.h"

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
    stop = false;
    //创建串口检查.每3s一次
    ui->stackedWidget->setCurrentWidget(ui->page_erro);
    ui->label_erro->setText("正在连接...");
    creatSerialCheck(3000);

    //判断串口是否正常打开


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

void CarsysWindow::creatSerialCheck(int msec)
{
    timerSerial = new QTimer(this);
    //绑定信号
    connect(timerSerial, SIGNAL(timeout()), this, SLOT(SerialCheck()));
    timerSerial->start(msec);
}
void CarsysWindow::SerialCheck()
{
   moddb.initSerail();
   switch(moddb.error)
   {
   case SERIAL_OPEN_SUCCES:	//串口打开成功
   {
       if(ui->stackedWidget->currentWidget() != ui->page_2)
       {
            ui->stackedWidget->setCurrentWidget(ui->page_2);
       }else
       {
    qDebug() << "---------";
       }

   }break;
   case SERIAL_OPEN_FAIL:	//串口打开失败
   {
        //跳转到运行页面
        ui->stackedWidget->setCurrentWidget(ui->page_erro);
        ui->label_erro->setText("串口打开失败");
   }break;
   }
}


void CarsysWindow::on_actionfull_screen_triggered()
{
    setParent(0);
    showFullScreen();

}

void CarsysWindow::on_actionout_full_screen_triggered()
{

}
