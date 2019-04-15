#include "modbushandle.h"

modbusHandle::modbusHandle()
{
    //初始化串口
    error = initSerail();

}
