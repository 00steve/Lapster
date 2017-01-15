#include "Quaternion.h"

Quaternion::Quaternion(double x,double y,double z,double w) :
        x(x),y(y),z(z),w(w){
}

Quaternion::Quaternion(Double3 offset) :
    x(offset.X),
    y(offset.Y),
    z(offset.Z),
    w(1) {
    Normalize();
}

Quaternion::Quaternion(){
}
Quaternion::Quaternion(Double3 axis,double angle){
    w  = cosf( angle/2);
    x = axis.X * sinf( angle/2 );
    y = axis.Y * sinf( angle/2 );
    z = axis.Z * sinf( angle/2 );
    Normalize();
}


void Quaternion::Normalize(){
    magnitude = Magnitude();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
    w /= magnitude;
}

double Quaternion::Magnitude(){
    return sqrt(w*w + x*x + y*y + z*z);
}

/*
Quaternion Quaternion::operator * (const Quaternion other){
    return Quaternion(
        w*other.x + x*other.w + y*other.z - z*other.y,
        w*other.y - x*other.z + w*other.w + z*other.x,
        w*other.z + x*other.y - y*other.x + z*other.w,
        w*other.w - x*other.x - y*other.y - z*other.z);
}*/



Quaternion Quaternion::Conjugate(){
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

Quaternion Quaternion::GetConjugate(){
    return Quaternion(-x,-y,-z,w);
}

Quaternion Quaternion::GetDelta(Quaternion q){
    return GetConjugate() * q;
}


Quaternion Quaternion::operator *(const Quaternion &b){
    Quaternion result;
    result.w = (b.w * w) - (b.x * x) - (b.y * y) - (b.z * z);
    result.x = (b.w * x) + (b.x * w) + (b.y * z) - (b.z * y);
    result.y = (b.w * y) + (b.y * w) + (b.z * x) - (b.x * z);
    result.z = (b.w * z) + (b.z * w) + (b.x * y) - (b.y * x);
    result.Normalize();
    return(result);
}




Double3 Quaternion::Vector(){
        // Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
        double roll = atan2(2.0f * (w *x + y * z), 1.0f - 2.0f * (x * x + y * y));
        double pitch = 2.0f * (w * y - z * x);
        pitch = pitch > 1 ? 1 : pitch;
        pitch = pitch < -1 ? -1 : pitch;
        //float pitch = asin(max(-1.0f, min(1.0f, 2.0f * (w * y - z * x)))); //the equivelent of the left is the above
        double yaw = atan2(2.0f * (w * z + x * y),1.0f - 2.0f * (y * y + z * z));

    return Double3(roll,pitch,yaw);
}


Double3 Quaternion::GetForwardVector(){
    return Double3( 2 * (x * z + w * y), 2 * (y * x - w * x), 1 - 2 * (x * x + y * y));
}

Double3 Quaternion::GetUpVector(){
    return Double3( 2 * (x * y - w * z), 1 - 2 * (x * x + z * z), 2 * (y * z + w * x));
}

Double3 Quaternion::GetRightVector(){
    return Double3( 1 - 2 * (y * y + z * z), 2 * (x * y + w * z), 2 * (x * z - w * y));
}


Double3 Quaternion::operator *(Double3 v){
    Quaternion vf = Quaternion(v);
    vf = vf * GetConjugate();
    vf = *this * vf;
    return Double3(vf.x, vf.y, vf.z).Normalize();
}

Double3* Quaternion::Rotate(Double3* v,unsigned int c){
    while(c --> 0){
        v[c] = *this * v[c];
    }
    return v;
}


void Quaternion::Print(){
    Serial.print(x);
    Serial.print("\t");
    Serial.print(y);
    Serial.print("\t");
    Serial.print(z);
    Serial.print("\t");
    Serial.println(w);
}


Quaternion Quaternion::Forward(){
    return Quaternion(0,0,0,1);
}
Quaternion Quaternion::Backward(){
    return Quaternion(0,1,0,0);
}
Quaternion Quaternion::Down(){
    return Quaternion(.7068,0,0,.7068);
}
Quaternion Quaternion::Up(){
    return Quaternion(-.7068,0,0,.7068);
}
Quaternion Quaternion::Right(){
    return Quaternion(0,-.7068,0,.7068);
}
Quaternion Quaternion::Left(){
    return Quaternion(0,.7068,0,.7068);
}


Quaternion Quaternion::RotateX(double x){
    return Quaternion(sin(x/2),0,0,cos(x/2));
}
Quaternion Quaternion::RotateY(double y){
    return Quaternion(0,sin(y/2),0,cos(y/2));
}
Quaternion Quaternion::RotateZ(double z){
    return Quaternion(0,0,sin(z/2),cos(z/2));
}

