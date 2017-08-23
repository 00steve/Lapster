#ifndef DATAWRITER_H
#define DATAWRITER_H

class DataWriter{
public:

    virtual bool Available();
    virtual bool Write(char *buffer,unsigned int length);

};

#endif // WRITER_H
