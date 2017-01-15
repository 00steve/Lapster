#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Input.h>
#include <MathUtils.h>

class Accelerometer : public Input{
private:

    static int xPin;
    static int yPin;
    static int zPin;
    static Double3 acceleration;
    static Double3 gravity;

    static Double3 oneGUp;
    static Double3 oneGDown;

protected:
    virtual void SetTilt(Double3 tilt);


public:
    virtual void Setup();
    virtual String StatusString();
    virtual void Update();
    virtual String Label();

    void Calibrate();

    Double3 Raw();

    double* XPtr();
    double* YPtr();
    double* ZPtr();
    Double3* AccelerationRef();

};






#endif // ACCEREROMETER_H
