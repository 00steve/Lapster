#ifndef QUATERNION_H
#define QUATERNION_H
/*REFERENCES
http://www.cprogramming.com/tutorial/3d/quaternions.html
*/



#include <math.h>
#include <Double3.h>

class Quaternion{
private:

    double x;
    double y;
    double z;
    double w;
    double magnitude;
    bool oldMagnitude;

    Quaternion(double x,double y,double z,double w);
    Quaternion(Double3 offset);

public:

    Quaternion();
    Quaternion(Double3 axis,double angle);

    void Normalize();
    double Magnitude();

    //Quaternion operator * (const Quaternion other);

    Quaternion Conjugate();
    Quaternion GetConjugate();
    Quaternion GetDelta(Quaternion q);
    Quaternion operator *(const Quaternion &b);

    Double3 Vector();
    Double3 GetForwardVector();
    Double3 GetUpVector();
    Double3 GetRightVector();
    Double3 operator *(Double3 v);

    static Quaternion Forward();
    static Quaternion Backward();
    static Quaternion Down();
    static Quaternion Up();
    static Quaternion Right();
    static Quaternion Left();



    /*


    //if the magnitude of the quaternion falls out of
    //the acceptable range, renormalize it to make it a
   // unit quaternion.




    //allow a quaternion to have a double3 added and return a
    //new double3 that combines the quaternion's offset and
    //the double3
    double3 operator +(double3 v){
        double3 t = double3(x,y,z).normalize();
        return t+v;
    }

    //converts the quaternion to a 4x4 rotation matrix. It can
    //be used by openGL to rotate something
    float* toMatrix(float* matrix){
        // First row
        matrix[0]	= 1.0f - 2.0f * ( y * y + z * z );
        matrix[1]	= 2.0f * (x * y + z * w);
        matrix[2]	= 2.0f * (x * z - y * w);
        matrix[3]	= 0.0f;
        // Second row
        matrix[4]	= 2.0f * ( x * y - z * w );
        matrix[5]	= 1.0f - 2.0f * ( x * x + z * z );
        matrix[6]	= 2.0f * (z * y + x * w );
        matrix[7]	= 0.0f;
        // Third row
        matrix[8]	= 2.0f * ( x * z + y * w );
        matrix[9]	= 2.0f * ( y * z - x * w );
        matrix[10]	= 1.0f - 2.0f * ( x * x + y * y );
        matrix[11]	= 0.0f;
        // Fourth row
        matrix[12]	= 0;
        matrix[13]	= 0;
        matrix[14]	= 0;
        matrix[15]	= 1.0f;
        return matrix;
    }


	float* toRotationMatrix(float* matrix){
        matrix[0]=1;
        matrix[1]=0;//4
        matrix[2]=0;//8
        matrix[3]=0;

        matrix[4]=0;//1
        matrix[5]=1;
        matrix[6]=0;//9
        matrix[7]=0;

        matrix[8]=0;//2
        matrix[9]=0;//6
        matrix[10]=1;
        matrix[11]=0;
		double3 forw = getForwardVector();
        matrix[12]= -forw.x * 57.29578f;
        matrix[13]= -forw.y * 57.29578f;
        matrix[14]= -forw.z * 57.29578f;
        matrix[15]=1;

        return matrix;
	}


    //gets the quaternion representation of the difference between
    //this quaternion and another quaternion.
    quaternion getDelta(quaternion q){
        //x = -x;y = -y;z = -z;//conjugate
        //quaternion result = *this * q;
        //x = -x;y = -y;z = -z;//conjugate
        return getConjugate() * q;
    }


    quaternion interpolate(quaternion q,double t){
        return quaternion(x*(1-t)+q.x*t, y*(1-t)+q.y*t, z*(1-t)+q.z*t, w*(1-t)+q.w*t);
    }

    void print(){
        cout << "(" << x << "," << y << "," << z << "," << w << ")\n";

    }


    static quaternion fromMatrix(float *r){
        return quaternion();
    }

	//some static functions to generate quaternions at
	//arbitrary rotations. They are generally used multipled
	//with existing quaternions to rotate them.
    static quaternion rotateX(double x){
        return quaternion(sin(x/2),0,0,cos(x/2));
    }
    static quaternion rotateY(double y){
        return quaternion(0,sin(y/2),0,cos(y/2));
    }
    static quaternion rotateZ(double z){
        return quaternion(0,0,sin(z/2),cos(z/2));
    }


    */

};




#endif
