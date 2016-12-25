#include "Accelerometer.h"

int Accelerometer::xPin = A1;
int Accelerometer::yPin = A2;
int Accelerometer::zPin = A3;
Double3 Accelerometer::acceleration = Double3(0,0,0);
Double3 Accelerometer::gravity = Double3(0,0,0);


void Accelerometer::SetTilt(Double3 tilt){
}

void Accelerometer::Calibrate(){
    Double3 avg = Double3(0,0,0);
    int iterations = 20;
    int i=iterations;
    while(i --> 0){
        acceleration.X += analogRead(xPin);
        acceleration.Y += analogRead(yPin);
        acceleration.Z += analogRead(zPin);
    }
    gravity = avg/iterations;
}

void Accelerometer::Setup(){
    Serial.print("[Accelerometer] - setup, nothing to do\n");

}

String Accelerometer::StatusString(){
    return "(" + String(acceleration.X) + "," + String(acceleration.Y) + "," + String(acceleration.Z) + ")\n";
}

void Accelerometer::Update(){
    acceleration.X = analogRead(xPin);
    acceleration.Y = analogRead(yPin);
    acceleration.Z = analogRead(zPin);
    newData = true;
}

String Accelerometer::Label(){
    return "Acceleratometer";
}

Double3 Accelerometer::Raw(){ return acceleration; }


