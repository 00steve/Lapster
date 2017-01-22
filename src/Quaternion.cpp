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

Quaternion::Quaternion(Double3 direction,Double3 up){

        direction.Normalize();
        up.Normalize();

        Double3 vector1 = direction;
        Double3 vector2 = up ^ direction;
        Double3 vector3 = vector1 ^ vector2;

        double m00 = vector2.X;
        double m01 = vector2.Y;
        double m02 = vector2.Z;
        double m10 = vector3.X;
        double m11 = vector3.Y;
        double m12 = vector3.Z;
        double m20 = vector1.X;
        double m21 = vector1.Y;
        double m22 = vector1.Z;

        double num8 = (m00 + m11) + m22;
        if (num8 > 0.0)
        {
            double num = (double)sqrt(num8 + 1.0);
            w = num * 0.5;
            num = 0.5 / num;
            x = (m12 - m21) * num;
            y = (m20 - m02) * num;
            z = (m01 - m10) * num;
            return;
        }
        if ((m00 >= m11) && (m00 >= m22))
        {
            double num7 = (double)sqrt(((1.0 + m00) - m11) - m22);
            double num4 = 0.5 / num7;
            x = 0.5 * num7;
            y = (m01 + m10) * num4;
            z = (m02 + m20) * num4;
            w = (m12 - m21) * num4;
            return;
        }
        if (m11 > m22)
        {
            double num6 = (double)sqrt(((1.0 + m11) - m00) - m22);
            double num3 = 0.5 / num6;
            x = (m10 + m01) * num3;
            y = 0.5 * num6;
            z = (m21 + m12) * num3;
            w = (m20 - m02) * num3;
            return;
        }
        double num5 = (double)sqrt(((1.0 + m22) - m00) - m11);
        double num2 = 0.5 / num5;
        x = (m20 + m02) * num2;
        y = (m21 + m12) * num2;
        z = 0.5 * num5;
        w = (m01 - m10) * num2;
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

