#include "Accelerometer.h"

int Accelerometer::xPin = A1;
int Accelerometer::yPin = A2;
int Accelerometer::zPin = A3;
Double3 Accelerometer::acceleration = Double3(0,0,0);
Double3 Accelerometer::gravity = Double3(0,0,0);

Double3 Accelerometer::oneGUp = Double3(2500,2500,2500);
Double3 Accelerometer::oneGDown = Double3(1660,1660,1660);

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
    oneGUp = Double3(2500,2515,2518);
    oneGDown = Double3(1660,1690,1690);


    Serial.print("[Accelerometer] - setup, nothing to do\n");

}

String Accelerometer::StatusString(){
    return "(" + String(acceleration.X) + "," + String(acceleration.Y) + "," + String(acceleration.Z) + ")\n";
}

void Accelerometer::Update(){
    //acceleration.X = analogRead(xPin);
    //acceleration.Y = analogRead(yPin);
    //acceleration.Z = analogRead(zPin);

    acceleration.X = Map(analogRead(xPin),oneGDown.X,oneGUp.X,-1,1);
    acceleration.Y = Map(analogRead(yPin),oneGDown.Y,oneGUp.Y,-1,1);
    acceleration.Z = Map(analogRead(zPin),oneGDown.Z,oneGUp.Z,-1,1);

    //Serial.print(acceleration.X);
    //Serial.print("\t");
    //Serial.print(acceleration.Y);
    //Serial.print("\t");
    //Serial.print(acceleration.Z);

    //double totalAccel = acceleration.Length();

    //Serial.print("\ttotal accel (inc. grav) ");
    //Serial.println(totalAccel);


    newData = true;
}

String Accelerometer::Label(){
    return "Acceleratometer";
}

Double3 Accelerometer::Raw(){ return acceleration; }

double* Accelerometer::XPtr(){ return &acceleration.X; }
double* Accelerometer::YPtr(){ return &acceleration.Y; }
double* Accelerometer::ZPtr(){ return &acceleration.Z; }
Double3* Accelerometer::AccelerationRef(){ return &acceleration; }

