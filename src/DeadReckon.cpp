#include <DeadReckon.h>



DeadReckon::DeadReckon(){
    //current position starts at the origin

    //Serial.print("GCD: 1.57:0 -> 3.14:0 ");
    //Serial.println(GreatCircleDistance(1.57,0,3.14,0));

    calibrating = false;

}

double DeadReckon::GeocentricRadius(double angle){
    return sqrt( ((earthRadiusEquator*earthRadiusEquator*cos(angle))*(earthRadiusEquator*earthRadiusEquator*cos(angle))
        + (earthRadiusPolar*earthRadiusPolar*sin(angle))*(earthRadiusPolar*earthRadiusPolar*sin(angle)))
        / ((earthRadiusEquator*cos(angle))*(earthRadiusEquator*cos(angle))
        + (earthRadiusEquator*sin(angle))*(earthRadiusEquator*sin(angle))));
}


double DeadReckon::GreatCircleDistance(double xA,double yA,double xB,double yB){
   double d = 2*asin(sqrt(    ((sin((yA-yB)/2))*(sin((yA-yB)/2)))      +
                 cos(yA)*cos(yB)*   ((sin((xA-xB)/2))*(sin((xA-xB)/2)))      ));
                 return d;
}


void DeadReckon::Calibrate(){
    calibrating = true;
    calibrationIterationsLeft = calibrationIterations;
    acc = new Double3[calibrationIterations];
    mag = new Double3[calibrationIterations];
}


void DeadReckon::LatitudeRef(double* newLatitudeRef){ latitudeRef = newLatitudeRef; }
void DeadReckon::LongitudeRef(double* newLongitudeRef){ longitudeRef = newLongitudeRef; }
void DeadReckon::AltitudeRef(double* newAltitudeRef){ altitudeRef = newAltitudeRef; }
void DeadReckon::AccelerationRef(Double3* newAccelerationRef){ accelerationRef = newAccelerationRef; }
void DeadReckon::MagneticNorthRef(Double3* newMagneticNorthRef){ magneticNorthRef = newMagneticNorthRef; }

void DeadReckon::Update(){
    //copy from references
    currentLatitude = *latitudeRef * radm; //convert to radians
    currentLongitude = *longitudeRef * radm; //convert to radians
    currentAltitude = *altitudeRef;

    //get derived values
    geocentricRadius = GeocentricRadius(currentLatitude);
    currentTotalRadius = geocentricRadius + currentAltitude;

    //get motion


    //Serial.println(geocentricRadius);




    //if calibrating
    if(calibrating){
        acc[--calibrationIterationsLeft] = *accelerationRef;
        mag[calibrationIterationsLeft] = *magneticNorthRef;
        if(!calibrationIterationsLeft){
            int dp = calibrationIterations/2;
            int it = 0;
            while(dp > 0){
                while(it < dp){
                    acc[it] = (acc[it] + acc[it+dp]) / 2;
                    mag[it] = (mag[it] + mag[it+dp]) / 2;
                    ++it;
                }
                dp = dp / 2;
                it = 0;
            }
            calibrating = false;
            downVector = acc[0];
            leftVector = (mag[0] ^ downVector).Normalize();
            backVector = (downVector ^ leftVector).Normalize();
            delete acc;
            delete mag;

            Serial.print("down vector : ");
            Serial.print(downVector.X);
            Serial.print(",");
            Serial.print(downVector.Y);
            Serial.print(",");
            Serial.println(downVector.Z);


            Serial.print("left vector : ");
            Serial.print(leftVector.X);
            Serial.print(",");
            Serial.print(leftVector.Y);
            Serial.print(",");
            Serial.println(leftVector.Z);

            Serial.print("back vector : ");
            Serial.print(backVector.X);
            Serial.print(",");
            Serial.print(backVector.Y);
            Serial.print(",");
            Serial.println(backVector.Z);

        }
    }//end of if calibrating


    previousLatitude = currentLatitude;
    previousLongitude = currentLongitude;
    previousAltitude = currentAltitude;
    previousTotalRadius = currentTotalRadius;
}
