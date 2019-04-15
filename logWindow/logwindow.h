#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QTime>

#include "logWindow/loginfunc.h"
#include "carsyswindow.h"


namespace Ui {
class logWindow;
}

class logWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit logWindow(QWidget *parent = 0);
    ~logWindow();
    void clearAlltext();              //清空
    void initCarsysWindow();               //初始化

private slots:
    void on_bt_Register_clicked();      //按钮_跳转：注册页面

    void on_bt_R_giveup_clicked();      //按钮_跳转：转登录页面

    void on_bt_Login_clicked();         //按钮_输入:登录

    void on_bt_NowRegister_clicked();   //按钮_输入:注册

    void LogOut();                      //注销


    void on_labe_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::logWindow *ui;
    loginFunc *logdb;
    CarsysWindow *carSysdb;
    UserData userInf;

};

#endif // LOGWINDOW_H
