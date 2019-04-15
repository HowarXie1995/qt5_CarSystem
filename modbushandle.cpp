#include "modbushandle.h"
#include <QTime>
#include <QCoreApplication>

modbusHandle::modbusHandle()
{
    //初始化串口
    error = initSerail();
    stop = false;

}

ERROR modbusHandle::initSerail()
{
    //创建串口
      serial.setPortName("COM2");			//串口名
      serial.setBaudRate(QSerialPort::Baud9600);		//波特率
      serial.setDataBits(QSerialPort::Data8);		//数据位
      serial.setParity(QSerialPort::NoParity);		//奇偶校验
      serial.setStopBits(QSerialPort::OneStop);		//停止位
      serial.setFlowControl(QSerialPort::NoFlowControl);	//流控制
      bool ok = serial.open(QIODevice::ReadWrite);
      if(ok)
      {
          return SERIAL_OPEN_SUCCES;
      }else
      {
          return SERIAL_OPEN_FAIL;
      }

}

void modbusHandle::reinitSerail()
{
    while(error == SERIAL_OPEN_FAIL && stop == false)
    {
         error = initSerail();
        qDebug() << "read Time" ;
    }
}
