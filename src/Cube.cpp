#include "Cube.h"



Cube::Cube(){
    p = new Double3[8]();
    p[0] = Double3(-.5,-.5,-.5);
    p[1] = Double3(.5,-.5,-.5);
    p[2] = Double3(.5,-.5,.5);
    p[3] = Double3(-.5,-.5,.5);
    p[4] = Double3(-.5,.5,-.5);
    p[5] = Double3(.5,.5,-.5);
    p[6] = Double3(.5,.5,.5);
    p[7] = Double3(-.5,.5,.5);
    r = Quaternion::Forward();
}

Cube::~Cube(){
    delete p;
}

void Cube::Draw(Project3d* project3dRef){
    p[0] = Double3(-.5,-.5,-.5);
    p[1] = Double3(.5,-.5,-.5);
    p[2] = Double3(.5,-.5,.5);
    p[3] = Double3(-.5,-.5,.5);
    p[4] = Double3(-.5,.5,-.5);
    p[5] = Double3(.5,.5,-.5);
    p[6] = Double3(.5,.5,.5);
    p[7] = Double3(-.5,.5,.5);
    r.Rotate(p,8);
    //projection.Color(projection.Color() + 10);
    project3dRef->DrawLine(p[0],p[1]);
    project3dRef->DrawLine(p[1],p[2]);
    project3dRef->DrawLine(p[2],p[3]);
    project3dRef->DrawLine(p[3],p[0]);
    project3dRef->DrawLine(p[4],p[5]);
    project3dRef->DrawLine(p[5],p[6]);
    project3dRef->DrawLine(p[6],p[7]);
    project3dRef->DrawLine(p[7],p[4]);
    project3dRef->DrawLine(p[0],p[4]);
    project3dRef->DrawLine(p[1],p[5]);
    project3dRef->DrawLine(p[2],p[6]);
    project3dRef->DrawLine(p[3],p[7]);
    //delete d;
}


void Cube::Rotate(Quaternion rotation){
    r = rotation;
}
