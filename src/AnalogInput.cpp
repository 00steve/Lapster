#include "AnalogInput.h"



AnalogInput::AnalogInput(int pin,int eepromOffset) :
    Input(),
    pin(pin){
    this->eepromOffset = eepromOffset;
}


void AnalogInput::Setup(){
    pinMode(pin, INPUT);

    voltMin = 0;
    voltMax = 5;
    mapMin = 0;
    mapMax = 100;
    //read from eeprom
    warnMin = mapMin;
    warnMax = mapMax;

    LoadSettings(eepromOffset);

}


void AnalogInput::SetTilt(Double3 tilt){
}


String AnalogInput::StatusString(){
    return "pin read : " + String(analogRead(pin)) + "\n";
}
void AnalogInput::Update(){
    voltage = analogRead(pin) / (double) MaxAnalogVoltageInt() * 5;
    value = Map(voltage,voltMin,voltMax,mapMin,mapMax);
    if(voltage > warnMax || voltage < warnMin){
        if(!currentAlert){
            currentAlert = true;
            alertInfo.object = (void*)this;
            //String m = String(voltage > warnMax ? "HIGH" : "LOW");// + String(" ") + String(label;
            alertInfo.message = String("stuff");// + (voltage < 1 ? "low":"high"));
            Alert(&alertInfo);
        }
    } else if(currentAlert){
        currentAlert = false;
        RemoveAlert(&alertInfo);
    }


}

String AnalogInput::Label(){
    return label;
}


/*
enabled     : char  : if the data source is being used
label       :char(16):holds name of the input (for ui)
units       :char(6) :holds unit type of input (for ui)
v_min       : short : minimum voltage that source will provide
                        Stored as 65535, each increment represents .0001 volts
                        as the min, a range of 0.0000 - 6.5535 volts at a scale of 4.
v_max       : short : maximum voltage that source will provide
                        Stored as 65535, each increment represents .0001 volts
                        as the min, a range of 0.0000 - 6.5535 volts at a scale of 4.
m_max       : float : what number of units the v_min maps to logged and displayed
                        Stored as a float so pretty much any value can be used.
m_min       : float : what number of units the v_max maps to when logged and displayed
                        Stored as a float so pretty much any value can be used.
w_min       : char  : minimum number of units allowed before user is warned (to turn off warning, set to min)
                        (w_min is stored as a scale from 0..1 of v_min and v_max, displayed to user as the unit equivalent,
                        thus will change if the v_min/max or m_min/max changes).
                        Stored as char, which is 0-255, only using 0-250 for nice round numbers when converting to a
                        percentage
w_max       : char  : maximum number of units allowed before user is warned (to turn off warning, set to max)
                        (w_max is stored as a scale from 0..1 of v_min and v_max, displayed to user as the unit equivalent,
                        thus will change if the v_min/max or m_min/max changes)
                        Stored as char, which is 0-255, only using 0-250 for nice round numbers when converting to a
                        percentage
w_duration  : short : amount of time signal must be over/below threshold for the warning to fire
                        stored in centiseconds (.01 seconds)
*/
bool AnalogInput::StoreSettings(){
    Serial.println("store analog input settings");
    Serial.print("enabled : ");
    Serial.println(enabled);

    int offset = eepromOffset;
    unsigned char stuff = 0;
    Eprom::SetBit(stuff,0,enabled);
    Eprom::SetBit(stuff,1,ignoreAlert);
    Eprom::SetBit(stuff,2,record);

    Eprom::WriteChar(offset,stuff);
    Eprom::WriteUShort(offset,(unsigned short)(voltMin*10000));
    Eprom::WriteUShort(offset,(unsigned short)(voltMax*10000));
    Eprom::WriteFloat(offset,(float)mapMin);
    Eprom::WriteFloat(offset,(float)mapMax);
    Eprom::WriteUShort(offset,(unsigned short)(warnMin*10000));
    Eprom::WriteUShort(offset,(unsigned short)(warnMax*10000));

    //Eprom::WriteString(offset,label); offset += 16;
    return true;
}
bool AnalogInput::StoreSettingDefaults(int startingEepromOffset){
    Serial.println("[don't use this shit, fuck face!]");
    return true;
}

bool AnalogInput::LoadSettings(int startingEepromOffset){
    int offset = startingEepromOffset;

    unsigned char props = Eprom::ReadChar(offset);
    enabled = Eprom::GetBit(props,0);
    //Serial.println(props);
    ignoreAlert = Eprom::GetBit(props,1);
    record = Eprom::GetBit(props,2);
    /*Serial.print("enabled : ");
    Serial.println(enabled);
    Serial.print("ignore alert : ");
    Serial.println(ignoreAlert);
    Serial.print("record : ");
    Serial.println(record);*/


    voltMin = (double)Eprom::ReadUShort(offset)/10000;
    voltMax = (double)Eprom::ReadUShort(offset)/10000;
    mapMin = Eprom::ReadFloat(offset);
    mapMax = Eprom::ReadFloat(offset);
    warnMin = (double)Eprom::ReadUShort(offset)/10000;
    warnMax = (double)Eprom::ReadUShort(offset)/10000;



    return true;
}

void AnalogInput::RestoreInputSettings(int startingEepromOffset){
    int offset = startingEepromOffset;
    unsigned char stuff = (unsigned char)0;
    Eprom::SetBit(stuff,0,true);//enabled
    Eprom::SetBit(stuff,1,false);//ignore alert
    Eprom::SetBit(stuff,2,true);//record
    Eprom::WriteChar(offset,stuff);
    Eprom::WriteUShort(offset,(unsigned short)0);
    Eprom::WriteUShort(offset,(unsigned short)33000);
    Eprom::WriteFloat(offset,(float)0);
    Eprom::WriteFloat(offset,(float)100);
    Eprom::WriteUShort(offset,(unsigned short)0);
    Eprom::WriteUShort(offset,(unsigned short)50000);
}


double AnalogInput::Value(){
    return value;
}
double* AnalogInput::ValueRef(){
    return &value;
}


double AnalogInput::Voltage(){
    return voltage;
}
double* AnalogInput::VoltageRef(){
    return &voltage;
}

double AnalogInput::MinimumVoltage(){
    return voltMin;
}
double AnalogInput::MaximumVoltage(){
    return voltMax;
}
double AnalogInput::MinimumMap(){
    return mapMin;
}
double AnalogInput::MaximumMap(){
    return mapMax;
}
double AnalogInput::MinimumWarning(){
    return warnMin;
}
double AnalogInput::MaximumWarning(){
    return warnMax;
}


double* AnalogInput::MinimumVoltageRef(){
    return &voltMin;
}
double* AnalogInput::MaximumVoltageRef(){
    return &voltMax;
}
double* AnalogInput::MinimumMapRef(){
    return &mapMin;
}
double* AnalogInput::MaximumMapRef(){
    return &mapMax;
}
double* AnalogInput::MinimumWarningRef(){
    return &warnMin;
}
double* AnalogInput::MaximumWarningRef(){
    return &warnMax;
}


String* AnalogInput::LabelRef(){
    return &label;
}


