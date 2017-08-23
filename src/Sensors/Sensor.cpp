#include "Sensor.h"


bool Sensor::Calibrate(){
    return false;
};

void Sensor::Print(){
    Serial.print("[abstract sensor]\n");
};

void Sensor::Setup(){
};
