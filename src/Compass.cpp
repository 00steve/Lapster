#include "Compass.h"

/*define static variables which will pretty much be anything that reads from
the compass. There is only one, so it only makes sense to read to the same
variables that can be accessed from anywhere.*/
bool Compass::initialized = false;
Adafruit_HMC5883_Unified Compass::mag = Adafruit_HMC5883_Unified(12345);
sensors_event_t Compass::event;
float Compass::heading;
float Compass::declinationAngle = 0.157; //waukesha has 3deg. 32' declination
float Compass::headingDegrees;

Double3 Compass::directionVector = Double3(0,0,1);


void Compass::Setup(){

    if(initialized) return;
    if(!mag.begin()) {
        /* There was a problem detecting the HMC5883 ... check your connections */
        Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
        return;
    }
    Serial.println("[initialize] compass");
    initialized = true;
    sensor_t sensor;
    mag.setMagGain(HMC5883_MAGGAIN_5_6);
    Serial.println("------------------------------------");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
    Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
    Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
    Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
    Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");
    Serial.println("------------------------------------");


    record = true;
}


void Compass::Update(){
    mag.getEvent(&Compass::event);
    Compass::heading = atan2(Compass::event.magnetic.y, Compass::event.magnetic.x);
    Compass::heading += Compass::declinationAngle;
    // Correct for when signs are reversed.
    if(Compass::heading < 0) Compass::heading += 2*PI;
    // Check for wrap due to addition of declination.
    if(Compass::heading > 2*PI) Compass::heading -= 2*PI;
    Compass::headingDegrees = Compass::heading * 180/M_PI;

    directionVector.X = Compass::event.magnetic.x;
    directionVector.Y = Compass::event.magnetic.y;
    directionVector.Z = Compass::event.magnetic.z;
    directionVector.Normalize();
    /*
    Serial.print(directionVector.X);
    Serial.print("\t");
    Serial.print(directionVector.Y);
    Serial.print("\t");
    Serial.println(directionVector.Z);
    */

    newData = true;
}

String Compass::Label(){
    return "Compass";
}


void Compass::SetTilt(Double3 tilt){
}


Double3 Compass::Raw(){
    return Double3(event.magnetic.x,event.magnetic.y,event.magnetic.z);
}


String Compass::StatusString(){
    return "X: \t"+ String(event.magnetic.x) + "," + String(event.magnetic.y) + "\n";
}


Double3 Compass::DirectionVector(){
    return directionVector;
}



