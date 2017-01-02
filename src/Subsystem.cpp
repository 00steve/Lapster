#include "Subsystem.h"


bool Subsystem::newAlert = false;
bool Subsystem::logging = false;

AnalogInput *Subsystem::AnalogInputs[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

Touch Subsystem::touch = Touch();
Screen Subsystem::screen = Screen();
/*global gps object. Make sure anything using gps is included after the
datalogger and shit nad stuff, bro.*/
HardwareSerial &gpsSerial = Serial1;
GPS Subsystem::gps(&gpsSerial,true);
Compass Subsystem::compass = Compass();
Accelerometer Subsystem::accelerometer = Accelerometer();
Gyrometer Subsystem::gyrometer = Gyrometer();
Timer Subsystem::timer = Timer();
Eprom Subsystem::eeprom = Eprom();


bool Subsystem::Setup(){
    analogReadAveraging(32);
    analogReadResolution(ANALOG_INPUT_BITS);
    Serial.begin(57600);
    Wire.begin();

    eeprom.Setup();
    timer.Setup();
    timer.TicksPerSecond(100);
    timer.DropTicks(true);
    screen.Setup();
    touch.Setup();
    gps.Setup();
    //compass.Setup();
    gyrometer.Setup();
    accelerometer.Setup();
    compass.Setup();

    sdCard.Setup();

    //setup analog inputs
    AnalogInputs[0] = new AnalogInput(A0,DATA_LOG_EXPANSION1_MEM_BLOCK);
    AnalogInputs[0]->Setup();

    return true;
}


void Subsystem::Update(){
    timer.Update();
    if(timer.Tick()){
        touch.Update();
        gps.Update();

        //Serial.println(gps.Position().X);
        compass.Update();
        accelerometer.Update();
        gyrometer.Update();
        AnalogInputs[0]->Update();
        if(logging){
            LogState();
        }
    }
}

void Subsystem::LogBegin(){
        SDCard::WriteByte(5);

            /*write column headers
            1 BYTE : column length (in bytes)
            1 BYTE : column datatype
            1 BYTE : length of column label
            n BYTEs: string that represents column label
            */

        SDCard::WriteByte(4);
        SDCard::WriteByte(DATATYPE_LONG);
        SDCard::WriteByte(4);
        SDCard::WriteString("time");

        SDCard::WriteByte(24);
        SDCard::WriteByte(DATATYPE_DOUBLE);
        SDCard::WriteByte(12);
        SDCard::WriteString("acceleration");

        SDCard::WriteByte(24);
        SDCard::WriteByte(DATATYPE_DOUBLE);
        SDCard::WriteByte(8);
        SDCard::WriteString("rotation");

        SDCard::WriteByte(24);
        SDCard::WriteByte(DATATYPE_DOUBLE);
        SDCard::WriteByte(14);
        SDCard::WriteString("magnetic north");

        SDCard::WriteByte(24);
        SDCard::WriteByte(DATATYPE_DOUBLE);
        SDCard::WriteByte(3);
        SDCard::WriteString("gps");

}

void Subsystem::LogState(){
    byte newSensorData;
    eeprom.SetBit(newSensorData,0,timer.NewData());
    eeprom.SetBit(newSensorData,1,accelerometer.NewData());
    eeprom.SetBit(newSensorData,2,gyrometer.NewData());
    eeprom.SetBit(newSensorData,3,compass.NewData());
    eeprom.SetBit(newSensorData,4,gps.NewData());

    SDCard::WriteByte(newSensorData);

    if(eeprom.GetBit(newSensorData,0)){
        SDCard::WriteLong(timer.Milliseconds());
    }
    if(eeprom.GetBit(newSensorData,1)){
        SDCard::WriteDouble(accelerometer.Raw().X);
        SDCard::WriteDouble(accelerometer.Raw().Y);
        SDCard::WriteDouble(accelerometer.Raw().Z);
    }
    if(eeprom.GetBit(newSensorData,2)){
        SDCard::WriteDouble(gyrometer.DPS().X);
        SDCard::WriteDouble(gyrometer.DPS().Y);
        SDCard::WriteDouble(gyrometer.DPS().Z);
    }
    if(eeprom.GetBit(newSensorData,3)){
        SDCard::WriteDouble(compass.Raw().X);
        SDCard::WriteDouble(compass.Raw().Y);
        SDCard::WriteDouble(compass.Raw().Z);
    }
    if(eeprom.GetBit(newSensorData,4)){
        SDCard::WriteDouble(gps.longitude);
        SDCard::WriteDouble(gps.altitude);
        SDCard::WriteDouble(gps.latitude);
    }

}



bool Subsystem::NewAlert(){
    return Input::NewAlert();
}


void Subsystem::FactoryReset(){
    //Eprom::PopulateDefaults();
    AnalogInput::RestoreInputSettings(DATA_LOG_EXPANSION1_MEM_BLOCK);

}

bool Subsystem::BeginLogging(){
    if(!SDCard::Ready()) return false;
    //try to get a date string
    String fileName;
    String datestring = DateString();
    if(datestring == ""){
        fileName = SDCard::GetNextFileName("LOGS/log::.lbr");
    } else {
        fileName = "Logs/log" + datestring + ".lbr";
    }
    if(sdCard.Exists(fileName)) return false;
    sdCard.MakeDir("LOGS/");
    logging = sdCard.WriteOpen(fileName);
    if(logging){
        LogBegin();
    }
    return logging;
}

bool Subsystem::EndLogging(){
    if(!logging || !sdCard.Writing()) return false;
    sdCard.WriteClose();
    return !(logging = false);
}


String Subsystem::DateString(){
    return "";
}


bool Subsystem::DataStreamRef(unsigned short input,DataStream** &streams,unsigned short &numStreams){
    switch(input){
    case INPUT_ACCELEROMETER:
        numStreams = 3;
        streams = new DataStream*[3];
        //double* streams[3] = {accelerometer.XPtr(),accelerometer.YPtr(),accelerometer.ZPtr()};
        //return streams;
        return true;



    case INPUT_ANALOG1:
        numStreams = 1;
        streams = new DataStream*[1];
        streams[0] = new DataStream();
        streams[0]->value = AnalogInputs[0]->ValueRef();
        streams[0]->mapMin = AnalogInputs[0]->MinimumMapRef();
        streams[0]->mapMax = AnalogInputs[0]->MaximumMapRef();
        streams[0]->input = AnalogInputs[0];
        return true;
    }
    return false;
}
