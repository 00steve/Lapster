#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <WString.h>


class DataStream{
private:
    char *buffer;
    unsigned int cursor;

public:
    DataStream(unsigned int bufferSize);
    void Clear();

    char& operator[](unsigned int index);
    DataStream& operator+=(const char value);


};


#endif // DATASTREAM_H
