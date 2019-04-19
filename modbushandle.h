#ifndef MODBUSHANDLE_H
#define MODBUSHANDLE_H


#include <iostream>
#include <cstring>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

typedef enum
{
   SERIAL_OPEN_FAIL = 10086,
   SERIAL_OPEN_SUCCES

}ERROR;


class modbusHandle
{
public:
    modbusHandle();

    //发送Modbus数据
    void sendSignal();

    //初始化串口
    void initSerail();
//================================================================================================================================
/*
 *函数名称: getErrorCode
 *函数功能: 返回错误码
 *函数参数: 无
 *函数返回值: 无
*/
    ERROR getErrorCode();


    //接收数据

private:
    ERROR error;		//错误码
    QSerialPort serial;		//串口接口

};

#endif // MODBUSHANDLE_H

/**********| |************/
//7
//================================================================================================================================
/*
 *函数名称:
 *函数功能:
 *函数参数:
 *函数返回值:
*/

//3
//================================================================================================================================
//private slots:/********************************私有************动作按钮函数**********************************************************/
//================================================================================================================================
