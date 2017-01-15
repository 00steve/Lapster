#ifndef PROJECT_3D_H
#define PROJECT_3D_H

#include <Int2.h>
#include <Double3.h>
#include <Double4x4.h>
#include <MathUtils.h>
#include <Drawable.h>
#include <Touch.h>


class Project3d : public Drawable {
private:
    double minDepth;
    double maxDepth;
    double depthRatio;

    Int2 topLeft;
    Int2 drawSize;

    unsigned int color;
    //Double4x4 viewMatrix;

    Int2 ProjectPoint(Double3 point);

public:
    Project3d();
    unsigned int Color(unsigned int color);
    unsigned int Color();
    void DrawLine(Double3 pointA,Double3 pointB);

    virtual void Draw();
};



#endif // PROJECT_3D_H
