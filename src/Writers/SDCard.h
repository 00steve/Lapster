#ifndef DATAWRITER_SD_H
#define DATAWRITER_SD_H
#include "DataWriter.h"
#include <SD.h>


class SDCard:public DataWriter{
public:

    virtual bool Available();
    virtual bool Write(char *buffer,unsigned int length);

};

#endif // DATA_WRITER_SD_H
