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
    ERROR initSerail();

    //接收数据

public:
    ERROR error;			//错误码
private:
    QSerialPort serial;		//串口接口

};

#endif // MODBUSHANDLE_H
