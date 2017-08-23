
#include "SubSystem.h"

Eprom SubSystem::eeprom;
Screen SubSystem::screen;
IntervalTimer SubSystem::timer;

//unsigned char SubSystem::sensorCount;
Sensor **SubSystem::sensors;
DataWriter **SubSystem::writers;

DataStream *SubSystem::data;

HardwareSerial &gpsSerial = Serial4;


void SubSystem::Setup(){
    /*set the analog read resolution to more precision*/
    analogReadResolution(12);
    analogReadAveraging(32);
    /*before the first things first, we need to look at what
    settings are being stored in EEPROM*/
    eeprom.Setup();

    /*first things first... get the screen up and running
    to give a pretty picture to the dummies that bought this
    shit or made this shit; they like shiny things. Show a
    cool logo that amps them bitches up and hangs out until
    all of the hard work is done.*/
    //screen = Screen();
    screen.Setup();


    /*setup sensors*/
    //sensorCount = 1;//this should be obtained through EEPROM
    sensors = new Sensor*[sensorCount];
    sensors[0] = new Accelerometer();
    sensors[1] = new GPS(&gpsSerial,true);

    /*setup the data writers*/
    writers = new DataWriter*[dataWriterCount];
    writers[0] = new USBRaw();
    //writers[1] = new DataWriterSD();





    data = new DataStream(256);


    /*start the sensor read and write interrupt.
    Right now it is set to 100fps, it should probably
    be adjusted depending on stuff.*/
    //timer.begin(SubSystem::Update,10000);
};


void SubSystem::Update(){
    data->Clear();
    byte newSensorData;
    int i=0;
    Serial.print("input ->");
    while(i<sensorCount){
        eeprom.SetBit(newSensorData,(i%8),sensors[i]->NewDataAvailable());
        Serial.print(sensors[i]->NewDataAvailable());
        Serial.print(":");
        if(++i%8 == 0){
            //data += newSensorData;
        }
    }
    Serial.print("\noutput->");
    i = 0;
    while(i<sensorCount){
        if(eeprom.GetBit((unsigned char)(*data)[i/8],i%8)){
        }
        Serial.print(eeprom.GetBit((unsigned char)(*data)[i/8],i%8) ? "1:" : "0:");
        ++i;
    }
    Serial.print("\n");

};
