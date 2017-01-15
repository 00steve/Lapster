#ifndef COMPASS_H
#define COMPASS_H


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>



#include <Input.h>


class Compass : public Input{
private:
    static bool initialized;
    static Adafruit_HMC5883_Unified mag;
    static sensors_event_t event;
    static float heading;
    static float declinationAngle;
    static float headingDegrees;

    static Double3 directionVector;



protected:
    virtual void SetTilt(Double3 tilt);


public:


    virtual void Setup();
    virtual String StatusString();
    virtual void Update();
    virtual String Label();

    Double3 Raw();
    static Double3 DirectionVector();
    static Double3* MagneticNorthRef();
};

#endif

