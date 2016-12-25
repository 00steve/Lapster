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
    warnMin = (double)20 / (double)255 * (double)5;
    warnMax = (double)200 / (double)255 * (double)5;
    //label = String("Oil Pressure");

    LoadSettings(eepromOffset);

}


void AnalogInput::SetTilt(Double3 tilt){
}


String AnalogInput::StatusString(){
    return "pin read : " + String(analogRead(pin)) + "\n";
}
void AnalogInput::Update(){
    voltage = analogRead(pin) / (double) MaxAnalogVoltageInt() * 5;
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
    Eprom::WriteChar(offset,enabled); offset ++;
    Eprom::WriteString(offset,label); offset += 16;
    return true;
}
bool AnalogInput::StoreSettingDefaults(int startingEepromOffset){
    Serial.println("store analog input settings");
    Serial.print("enabled : false");
    int offset = eepromOffset;
    Eprom::WriteChar(offset,(char)0); offset ++;
    Eprom::WriteString(offset,""); offset += 16;
    return true;
    //Eprom::Write
}

bool AnalogInput::LoadSettings(int startingEepromOffset){
    int offset = startingEepromOffset;
    enabled = Eprom::ReadChar(offset); offset ++;
    label = Eprom::ReadString(offset,16); offset += 16;

    return true;
}


double AnalogInput::Voltage(){
    return voltage;
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

String* AnalogInput::LabelRef(){
    return &label;
}

