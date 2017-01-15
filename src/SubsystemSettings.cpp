#include <SubsystemSettings.h>


SubsystemSettings::SubsystemSettings(){
    Setup();
    Redraw();
}
SubsystemSettings::~SubsystemSettings(){}

void SubsystemSettings::Setup(){
    t = Quaternion::Forward();
}

void SubsystemSettings::Update(){
    Double3* p = new Double3[8]();
    p[0] = Double3(-.5,-.5,-.5);
    p[1] = Double3(.5,-.5,-.5);
    p[2] = Double3(.5,-.5,.5);
    p[3] = Double3(-.5,-.5,.5);
    p[4] = Double3(-.5,.5,-.5);
    p[5] = Double3(.5,.5,-.5);
    p[6] = Double3(.5,.5,.5);
    p[7] = Double3(-.5,.5,.5);

    //t = Quaternion::RotateY(.01) * t;
    t = Quaternion::Forward() *
    //t.Print();
    t.Rotate(p,8);

    projection.Color(projection.Color() + 100);
    projection.DrawLine(p[0],p[1]);
    projection.DrawLine(p[1],p[2]);
    projection.DrawLine(p[2],p[3]);
    projection.DrawLine(p[3],p[0]);
    projection.DrawLine(p[4],p[5]);
    projection.DrawLine(p[5],p[6]);
    projection.DrawLine(p[6],p[7]);
    projection.DrawLine(p[7],p[4]);
    projection.DrawLine(p[0],p[4]);
    projection.DrawLine(p[1],p[5]);
    projection.DrawLine(p[2],p[6]);
    projection.DrawLine(p[3],p[7]);


    delete p;
    //Double3 d = t.GetForwardVector() + Double3(0,-.5,0);
    //projection.DrawLine(Double3(0,-.5,0),d);
}
void SubsystemSettings::Draw(){
}
void SubsystemSettings::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Subsystem");
    Draw();
}
