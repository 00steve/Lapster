#include "Input.h"


bool Input::newAlert = false;
AlertInfo *Input::alerts[24] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
short Input::alertCount = 0;
short Input::maxAnalogVoltageInt = pow(2,ANALOG_INPUT_BITS);


bool Input::Alert(AlertInfo* info){
    if(alertCount > 23) return false;
    alerts[alertCount++] = info;
    return newAlert = true;
}

bool Input::RemoveAlert(AlertInfo* info){
    int a = alertCount;
    //get index of the alert to remove
    while(a --> 0){
        if(alerts[a] == info) break;
    }
    if(a == -1) return false;
    //shift every alert behind it up one index
    while(a ++< alertCount){
        alerts[a-1] = alerts[a];
    }
    --alertCount;
    return true;
}

bool Input::NewAlert(){
    return newAlert ? !(newAlert=false) : false;
}


short Input::MaxAnalogVoltageInt(){
    return maxAnalogVoltageInt;
}

int Input::AlertCount(){
    return alertCount;
}

AlertInfo** Input::Alerts(){
    return alerts;
}

bool Input::StoreSettingDefaults(int startEepromOffset){
    Serial.println("store setting defaults not implemented for this input type");
    return false;
}

bool Input::StoreSettings(int startingEepromOffset){
    Serial.println("store settings not implemented for this input type");
    return false;
}
bool Input::StoreSettings(){
    return false;
}

bool Input::LoadSettings(int startingEepromOffset){
    Serial.println("load settings not implemented for this input type");
    return false;
}

bool Input::Enabled(){
    return enabled;
}

void Input::Enable(){ enabled = true; }
void Input::Disable(){ enabled = false; }

int Input::EepromOffset(){return eepromOffset;}


bool Input::NewData(){ return newData ? !(newData=false) : false; }

bool Input::Record(){ return record; }
