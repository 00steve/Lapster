#ifndef INT2_H
#define INT2_H

class Int2{
public:
    int x;
    int y;

    Int2();
    Int2(int x,int y);

    Int2 operator  + (const Int2 other);
    Int2 operator  - (const Int2 other);
    Int2 operator / (const int other);
    Int2 operator * (const int other);

    Int2 operator += (const Int2 other);
    Int2 operator -= (const Int2 other);

    Int2 operator / (const double other);
    Int2 operator * (const double other);
};



#endif
