#ifndef CUBE_H
#define CUBE_H

#include <Shape.h>

class Cube : public Shape{
private:

    Double3* p;
    Quaternion r;

public:
    Cube();
    ~Cube();

    virtual void Draw(Project3d* project3dRef);
    virtual void Rotate(Quaternion rotation);

};
#endif // CUBE_H
