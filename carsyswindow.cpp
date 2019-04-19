#include "carsyswindow.h"
#include "ui_carsyswindow.h"
#include <QDateTime>

CarsysWindow::CarsysWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarsysWindow)
{
    ui->setupUi(this);
    initCarSysWindow();							//初始化界面
    creatDataCheck(3000);						//创建数据检查定时器，传入3s



}

CarsysWindow::~CarsysWindow()
{
    if(nullptr != timerData){	//定时器关闭
        timerData->stop();
        delete timerData;
    }
    if(nullptr != myprocess){	//线程关闭
        delete myprocess;
    }
    delete timerNow;
    delete moddb;
    delete ui;
}

void CarsysWindow::getUserInf(UserData infor)
{
   userInf = infor;
   //获得用户数据
}

void CarsysWindow::initCarSysWindow()
{
    //堆分配内存
    moddb = new	modbusHandle();
    timerNow = new QTimer(this);

    //数据初始化
    timerData = nullptr;		//初始定时器
    myprocess = nullptr;		//初始化线程

    //开始进入错误页面
    ui->stackedWidget->setCurrentWidget(ui->page_erro);
    ui->label_erro->setText("正在连接...");
    //设置显示
    ui->label_CarLeft->setText("车位剩余数");
    ui->label_CarSum->setText("车位总数");
    //绑定定时器，并启动
    connect(timerNow, SIGNAL(timeout()), this, SLOT(displayTime()));	//启动定时器
    timerNow->start(1000);
}

void CarsysWindow::creatDataCheck(int msec)
{
    if(nullptr == timerData)
        timerData = new QTimer(this);
    //绑定信号
    connect(timerData, SIGNAL(timeout()), this, SLOT(DataCheck()));
    timerData->start(msec);
}

void CarsysWindow::displayTime()
{
   QDateTime dt = QDateTime::currentDateTime();
   int sec = (dt.toString("ss")).toInt();
   QString strTime;
   if(sec%2){	//带闪烁效果的时钟
       strTime = dt.toString("hh mm");
   }else{
       strTime = dt.toString("hh:mm");
   }
   ui->lcdNowTime->display(strTime);
   ui->lcdNowYear->display(dt.toString("yyyy"));
   ui->lcdNowMDay->display(dt.toString("MM-dd"));
   ui->label_Week->setText(dt.toString("ddd"));
}

void CarsysWindow::stopDataTimer()
{
   timerData->stop();
}
void CarsysWindow::DataCheck()
{
   moddb->initSerail();
   switch(moddb->getErrorCode())
   {
   case SERIAL_OPEN_SUCCES:	//串口打开成功
   {
       if(ui->stackedWidget->currentWidget() != ui->page_oneFloor)
       {
            ui->stackedWidget->setCurrentWidget(ui->page_oneFloor);
       }else
       {
            qDebug() << "---------";
       }

   }break;
   case SERIAL_OPEN_FAIL:	//串口打开失败
   {
        //跳转到运行页面
       if(ui->stackedWidget->currentWidget() != ui->page_erro)
       {
            ui->stackedWidget->setCurrentWidget(ui->page_erro);
       }
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
    showNormal();
}

void CarsysWindow::on_actionexit_triggered()
{
   this->close();
   qApp->quit();
}
