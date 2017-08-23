#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include <Arduino.h>
#include <IntervalTimer.h>
#include <SPI.h>
#include "Eprom.h"
#include "Writers/USBRaw.h"
#include "Screen.h"
#include "Sensors/Accelerometer.h"
#include "Sensors/GPS.h"
#include "DataStream.h"

class SubSystem{
private:
    static Eprom eeprom;
    static Screen screen;
    static IntervalTimer timer;
    //static DataCollector collector;

    /*this will be dynamic based on what is in the EEPROM, or what
    a user adds through the GUI.*/
    const static unsigned char sensorCount = 2;
    static Sensor **sensors;
    /*setup all of the data writers to do their things no matter
    what, as part of the system overhead, if there are any devices
    connected, let them handle what to do (or not do if there are
    no devices connected)*/
    const static unsigned char dataWriterCount = 2;
    static DataWriter **writers;

    static DataStream *data;

public:

    static void Setup();
    static void Update();
};



#endif // SUBSYSTEM_H
