#ifndef SHAPE_H
#define SHAPE_H

#include <Quaternion.h>
#include <Project3d.h>

class Shape{

public:


    virtual void Draw(Project3d* project3dRef) = 0;
    virtual void Rotate(Quaternion rotation) = 0;


};

#endif // SHAPE_H


