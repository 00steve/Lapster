#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#define INPUT_NONE -1
#define INPUT_GPS 0
#define INPUT_COMPASS 1
#define INPUT_ACCELEROMETER 2
#define INPUT_GYROMETER 3
#define INPUT_TOUCH 4
#define INPUT_TIMER 5
#define INPUT_ANALOG1 8
#define INPUT_ANALOG2 9
#define INPUT_ANALOG3 10
#define INPUT_ANALOG4 11
#define INPUT_ANALOG5 12
#define INPUT_ANALOG6 13
#define INPUT_ANALOG7 14
#define INPUT_ANALOG8 15


#define DATATYPE_BYTE 0
#define DATATYPE_LONG 1
#define DATATYPE_DOUBLE 2
#define DATATYPE_FLOAT 3



#include <GPS.h>
#include <Compass.h>
#include <Accelerometer.h>
#include <Gyrometer.h>
#include <Touch.h>
#include <Screen.h>
#include <Timer.h>
#include <Eprom.h>
#include <AnalogInput.h>
#include <SDCard.h>
#include <DataStream.h>



class Subsystem{
private:

    static bool newAlert;
    static bool logging;


public:
    //static Timer stimer;
    static Timer timer;
    static Touch touch;
    static Screen screen;
    static GPS gps;
    static Compass compass;
    static Accelerometer accelerometer;
    static Gyrometer gyrometer;

    /*storage*/
    static Eprom eeprom;
    static SDCard sdCard;

    static bool Setup();
    static void Update();

    static bool NewAlert();

    /*create a static array of inputs that represents
    all of the analog inputs in the system*/
    static AnalogInput *AnalogInputs[8];

    /*reset all configurable settings to what they started as
    when the owner bought the lapsterbator.*/
    static void FactoryReset();

    static bool BeginLogging();
    static bool EndLogging();

    /*get the date as a string representation from the GPS
    chip if it is installed and it should be cool and stuff.

    If it cannot  be generated for some dumb fucking reason,
    it will return a blank string.*/
    static String DateString();

    static void LogBegin();
    static void LogState();

    /*get an array of data streams coming from an input, as an array of
    pointers to doubles. These doubles will always have the up-to-date values
    of the inputs they point to.*/
    static bool DataStreamRef(unsigned short input,DataStream** &streams,unsigned short &numStreams);

};

#endif
