#ifndef LISTCRC_H
#define LISTCRC_H
#include <iostream>
#include <cstring>

class listCRC
{
public:
    uint16_t   calCRC16(unsigned char *updata, unsigned int len);

};

#endif // LISTCRC_H
