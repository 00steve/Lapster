#include "DataLogger.h"


DataLogger::DataLogger(){
    if(!Subsystem::BeginLogging()){
        Serial.println("failed to start logging");
    } else {
        Serial.println("start logging");
    }
    Draw();
}
DataLogger::~DataLogger(){
    if(Subsystem::EndLogging()){
        Serial.println("end logging");
    }
}




void DataLogger::Update(){
    if(Button::CheckForScreenPress()){
        Set(MODE_MAIN_MENU);
    }
}

void DataLogger::Draw(){
    tft.fillScreen(0x0000);
    DrawTitle("Logging...");
}

void DataLogger::Redraw(){
}
