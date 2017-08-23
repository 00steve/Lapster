#include "Accelerometer.h"

Accelerometer::Accelerometer() {
    minVoltage[1] = 1600;
    maxVoltage[1] = 2390;
    minVoltage[2] = 1540;
    maxVoltage[2] = 2390;
    minVoltage[0] = 1560;
    maxVoltage[0] = 2430;


    pinMode(ACCELEROMETER_X_PIN,INPUT);
    pinMode(ACCELEROMETER_Y_PIN,INPUT);
    pinMode(ACCELEROMETER_Z_PIN,INPUT);
};

unsigned char Accelerometer::ColumnCount(){
    return 0;
};

String Accelerometer::ColumnLabel(unsigned char index){
    return "";
};

unsigned char Accelerometer::ColumnSize(unsigned char index){
    return 0;
};

char* Accelerometer::GetData(){
    return NULL;
};

bool Accelerometer::NewDataAvailable(){
    voltage[0] = analogRead(ACCELEROMETER_X_PIN);
    voltage[1] = analogRead(ACCELEROMETER_Y_PIN);
    voltage[2] = analogRead(ACCELEROMETER_Z_PIN);
    gForce[0] = (double)(voltage[0]-minVoltage[0]) /(double)(maxVoltage[0]-minVoltage[0])*2 - 1;
    gForce[1] = (double)(voltage[1]-minVoltage[1]) /(double)(maxVoltage[1]-minVoltage[1])*2 - 1;
    gForce[2] = (double)(voltage[2]-minVoltage[2]) /(double)(maxVoltage[2]-minVoltage[2])*2 - 1;
    /*Serial.print((double)(voltage[0]-minVoltage[0]) /(double)(maxVoltage[0]-minVoltage[0])*2 - 1);
    Serial.print("\t");
    Serial.print((double)(voltage[1]-minVoltage[1]) /(double)(maxVoltage[1]-minVoltage[1])*2 - 1);
    Serial.print("\t");
    Serial.println((double)(voltage[2]-minVoltage[2]) /(double)(maxVoltage[2]-minVoltage[2])*2 - 1);
    */
    return true;
};

unsigned char Accelerometer::NewDataByteSize(){
    return 0;
};
