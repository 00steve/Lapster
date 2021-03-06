#ifndef DEAD_RECKON_H
#define DEAD_RECKON_H

#include <Wire.h>
#include <Double3.h>
#include <Quaternion.h>


class DeadReckon{
private:
    //pre-known values needed for calculations
    const double earthRadiusEquator = 20925646.368;
    const double earthRadiusPolar = 20855486.784;
    const double pi = 3.14159265359;
    const double radm = 0.01745329252;

    const int calibrationIterations = 128;
    int calibrationIterationsLeft;
    bool calibrating;
    Double3* acc;
    Double3* mag;

    //configured data
    Double3 downVector;
    Double3 leftVector;
    Double3 backVector;
    Double3 initialRotationVector;

    //data read from sensors
    Quaternion initialRotation;
    Quaternion currentRotation;

    double* latitudeRef;
    double* longitudeRef;
    double* altitudeRef;
    Double3* accelerationRef;
    Double3* magneticNorthRef;

    double currentLatitude;
    double previousLatitude;
    double currentLongitude;
    double previousLongitude;
    double currentAltitude;
    double previousAltitude;


    Double3 currentPosition = Double3(0,0,0);

    //data derived from sensor data
    double geocentricRadius; //thickness of earth (in ft) at latitude
    double currentTotalRadius; //total distance from earth center in feet (altitude + earth thickness based on latitude)
    double previousTotalRadius; //last value of the total radius

    Double3 currentGPSMotion = Double3(0,0,0);
    Double3 previousGPSMotion = Double3(0,0,0);

    Double3 currentACCMotion = Double3(0,0,0);
    Double3 previousACCMotion = Double3(0,0,0);

    //knowledge learned from derived data
    bool inMotion;
    double speed;


    double GeocentricRadius(double angle);
    double GreatCircleDistance(double xA,double yA,double xB,double yB);

public:

    DeadReckon();

    /*should be called when vehicle is not moving. This will determine
    what angle gravity is at by default relative to the accelerometer.*/
    void Calibrate();


    void LatitudeRef(double* newLatitudeRef);
    void LongitudeRef(double* newLongitudeRef);
    void AltitudeRef(double* newAltitudeRef);

    void AccelerationRef(Double3* newAccelerationRef);
    void MagneticNorthRef(Double3* newMagneticNorthRef);

    void Update();



};







#endif // DEAD_RECKON_H
