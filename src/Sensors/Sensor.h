#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
private:

protected:

public:
    virtual bool Calibrate();

    virtual unsigned char ColumnCount() = 0;

    virtual String ColumnLabel(unsigned char index) = 0;

    virtual unsigned char ColumnSize(unsigned char index) = 0;

    virtual char* GetData() = 0;

    virtual bool NewDataAvailable() = 0;

    virtual unsigned char NewDataByteSize() = 0;

    virtual void Setup();

};
#endif // SENSOR_H
