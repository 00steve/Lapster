#ifndef DOUBLE3_H
#define DOUBLE3_H


#include <math.h>

class Double3{
public:

    double X;
    double Y;
    double Z;

    Double3();
    Double3(double x,double y,double z);

    Double3 Normalize();

    double Length();

    /*calculate the dot product of two double3s*/
    double operator * (const Double3 &other);

    /*calculate the cross product of two double3s, which is a vector
    tangent to plane that both input double3s lie on.*/
    Double3 operator ^ (const Double3 &other);

    Double3 operator + (const Double3 &other);
    Double3 operator - (const Double3 &other);

    Double3 operator /= (const double &other);
    Double3 operator / (const double &other);

};



#endif
