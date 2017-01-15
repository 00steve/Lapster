#include "Double3.h"

Double3::Double3(){};
Double3::Double3(double x,double y,double z) :
        X(x),Y(y),Z(z){
}


Double3 Double3::Normalize(){
    double len = sqrt(X*X + Y*Y + Z*Z);
    X /= len; Y /= len; Z /= len;
    return *this;
}

double Double3::Length(){ return sqrt(X*X + Y*Y + Z*Z); }

double Double3::operator * (const Double3 &other){
    return X*other.X + Y*other.Y + Z*other.Z;
}
Double3 Double3::operator ^ (const Double3 &other){
    return Double3( Y*other.Z - Z*other.Y, Z*other.X - X*other.Z, X*other.Y - Y*other.X);
}


Double3 Double3::operator + (const Double3 &other){ return Double3(X+other.X,Y+other.Y,Z+other.Z); }
Double3 Double3::operator - (const Double3 &other){ return Double3(X-other.X,Y-other.Y,Z-other.Z); }


Double3 Double3::operator /= (const double &other){
    X /= other; Y /= other; Z /= other;
    return *this;
}

Double3 Double3::operator / (const double &other){
    return Double3(X/other,Y/other,Z/other);
}
