#include "DataStream.h"



DataStream::DataStream(unsigned int bufferSize) :
    buffer(new char[bufferSize]),
    cursor(0)
        {
};

void DataStream::Clear(){
    cursor = 0;
};

char& DataStream::operator[](unsigned int index){
    return buffer[index];
}

DataStream& DataStream::operator+=(const char value){
    buffer[cursor++] = value;
    return *this;
};

