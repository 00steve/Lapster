#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "Sensor.h"

#define ACCELEROMETER_X_PIN A16
#define ACCELEROMETER_Y_PIN A17
#define ACCELEROMETER_Z_PIN A18


class Accelerometer : public Sensor{
private:
    unsigned short minVoltage[3];
    unsigned short maxVoltage[3];
    unsigned short voltage[3];
    double gForce[3];

public:

    Accelerometer();

    virtual bool NewDataAvailable();
    virtual unsigned char NewDataByteSize();
    virtual char* GetData();
    virtual unsigned char ColumnCount();
    virtual unsigned char ColumnSize(unsigned char index);
    virtual String ColumnLabel(unsigned char index);
};


#endif // ACCELEROMETER_H
