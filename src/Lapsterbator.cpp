#include "Lapsterbator.h"


void Lapsterbator::PrintLastError(){
    Serial.println("error: " + lastError);
}




bool Lapsterbator::Setup(){
    Serial.begin(57600);
    Serial.println("show screen')");
    lastError = "none";
    SubSystem::Setup();
    return false;
}

bool Lapsterbator::Update(){
    SubSystem::Update();
    delay(100);
    return false;
}
