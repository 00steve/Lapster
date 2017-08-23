#ifndef DATAWRITER_USB_RAW_H
#define DATAWRITER_USB_RAW_H
#include "DataWriter.h"

class USBRaw:public DataWriter{
public:

    virtual bool Available();
    virtual bool Write(char *buffer,unsigned int length);

};


#endif // WRITER_USB_RAW_H
