#include <DeadReckon.h>



DeadReckon::DeadReckon(){
    //current position starts at the origin

    Serial.print("GCD: 1.57:0 -> 3.14:0 ");
    Serial.println(GreatCircleDistance(1.57,0,3.14,0));
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

void DeadReckon::LatitudeRef(double* newLatitudeRef){ latitudeRef = newLatitudeRef; }
void DeadReckon::LongitudeRef(double* newLongitudeRef){ longitudeRef = newLongitudeRef; }
void DeadReckon::AltitudeRef(double* newAltitudeRef){ altitudeRef = newAltitudeRef; }


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


    previousLatitude = currentLatitude;
    previousLongitude = currentLongitude;
    previousAltitude = currentAltitude;
    previousTotalRadius = currentTotalRadius;
}
