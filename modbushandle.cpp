#include "modbushandle.h"
#include <QTime>
#include <QCoreApplication>
#include <QByteArray>

modbusHandle::modbusHandle()
{
    //初始化串口
    crcdb = new listCRC;
    initSerail();
    sendPrimary = true;
    retArray = nullptr;
    //sentModBus();

}

modbusHandle::~modbusHandle()
{
    if(nullptr != retArray){	//因为retArray是在analyData里面动态分配的
        delete retArray;
    }
    delete crcdb;
}

void modbusHandle::initSerail()
{
    //创建串口
      serial.setPortName("COM2");			//串口名
      serial.setBaudRate(QSerialPort::Baud9600);		//波特率
      serial.setDataBits(QSerialPort::Data8);		//数据位
      serial.setParity(QSerialPort::NoParity);		//奇偶校验
      serial.setStopBits(QSerialPort::OneStop);		//停止位
      serial.setFlowControl(QSerialPort::NoFlowControl);	//流控制
      bool ok = serial.open(QIODevice::ReadWrite);
      if(ok || serial.isOpen())
      {
          error = SERIAL_OPEN_SUCCES;
          return ;
      }else
      {
          error =  SERIAL_OPEN_FAIL;
          return ;
      }

}

ERROR modbusHandle::getErrorCode()
{
    return error;
}

void modbusHandle::sentModBus()
{
    if(SERIAL_OPEN_SUCCES == error && isCanSend()){
        //\x01\x03\x00\x00\x00\n\xC5\xCD
        QByteArray array;
        unsigned char a[8] = {0x01, 0x03, 0x00, 0x00, 0x00, '\n'};
        unsigned int c = (sizeof(a)/sizeof(char)) - 2;
        uint16_t calres = crcdb->calCRC16(a, c);
        uint16_t low = (calres & 0x00ff) ;
        uint16_t hight = calres >> 8;
        a[c] = hight;
        a[c+1] = low;
        for(unsigned int i = 0; i < c+2; ++i){
            array.append(a[i]);
        }
        qDebug() << "array " << array;
        serial.write(array);
        setSendPrimary(false);
        analyData(5);
    }else{//发送失败
       qDebug() << "发送失败" ;
    }

}

bool modbusHandle::isCanSend()
{
    return sendPrimary;
}

void modbusHandle::setSendPrimary(bool ok)
{
    sendPrimary = ok;
}

QByteArray modbusHandle::recvModBus()
{
    return serial.readAll();
}

char *modbusHandle::analyData(int num)
{
    num = 2;
    if(SERIAL_OPEN_SUCCES == error && !isCanSend()){
        if(nullptr == retArray){
             retArray = (char*)malloc(sizeof(char) * num * 4);
        }
        memset(retArray, 0, sizeof(char) * num * 4);
        QByteArray data = recvModBus();		//获得数据
        qDebug() << data.size();
        for(int i = 3; i < data.size() - 6 && i < num + 3; i+=4){
            unsigned char temp = data.at(i);
            for(int j = 3; j >= 0; --j){
                retArray[i + j] = temp & 0x03;
                qDebug("%c", retArray[i + j] + '0');
                temp = temp >> 2;
            }

        }
    }
    setSendPrimary(true);
    return retArray;
}

