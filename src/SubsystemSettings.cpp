#include <SubsystemSettings.h>


SubsystemSettings::SubsystemSettings(){
    Setup();
    Redraw();
}
SubsystemSettings::~SubsystemSettings(){}

void SubsystemSettings::Setup(){
    projection = Project3d(Int2(40,0),Int2(160,160));
    projection2 = Project3d(Int2(40,160),Int2(160,160));
    projection3 = Project3d(Int2(200,0),Int2(160,160));
    projection4 = Project3d(Int2(200,160),Int2(160,160));
    t = Quaternion::Forward();
}

void SubsystemSettings::Update(){
    /*
    Double3* p = new Double3[8]();
    p[0] = Double3(-.5,-.5,-.5);
    p[1] = Double3(.5,-.5,-.5);
    p[2] = Double3(.5,-.5,.5);
    p[3] = Double3(-.5,-.5,.5);
    p[4] = Double3(-.5,.5,-.5);
    p[5] = Double3(.5,.5,-.5);
    p[6] = Double3(.5,.5,.5);
    p[7] = Double3(-.5,.5,.5);
    */

    //tft.fillScreen(0x0000);

    //t = Quaternion::RotateY(.01) * t;
    Double3 mag = deadReckon.MagneticNorth();
    double mult = 30;
    tft.drawLine(400-mult,20,400+mult,20,0x0000);
    tft.drawLine(400,20,400+mag.X*mult,20,0xFFFF);
    tft.drawLine(400-mult,40,400+mult,40,0x0000);
    tft.drawLine(400,40,400+mag.Y*mult,40,0xFFFF);
    tft.drawLine(400-mult,60,400+mult,60,0x0000);
    tft.drawLine(400,60,400+mag.Z*mult,60,0xFFFF);


    //Double3 m;
    //m = Double3(mag.X*1,mag.Y*1,mag.Z*1);
    //t = Quaternion(m);
    projection.Clear();
    c.Rotate(deadReckon.Rotation());
    c.Draw(&projection);

    /*

    m = Double3(mag.X*-1,mag.Y*1,mag.Z*1);
    t = Quaternion(m);
    projection2.Clear();
    c.Rotate(t);
    c.Draw(&projection2);

    m = Double3(mag.X*1,mag.Y*-1,mag.Z*1);
    t = Quaternion(m);
    projection3.Clear();
    c.Rotate(t);
    c.Draw(&projection3);

    m = Double3(mag.X*-1,mag.Y*-1,mag.Z*1);
    t = Quaternion(m);
    projection4.Clear();
    c.Rotate(t);
    c.Draw(&projection4);*/

    /*
    //t.Print();
    t.Rotate(p,8);
    projection.Clear();
    //projection.Color(projection.Color() + 10);
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
    */

    //delete p;
    //Double3 d = t.GetForwardVector() + Double3(0,-.5,0);
    //projection.DrawLine(Double3(0,-.5,0),d);
}
void SubsystemSettings::Draw(){
}
void SubsystemSettings::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Subsystem");

    tft.drawLine(370,20,370,60,0xFF00);
    tft.drawLine(400,20,400,60,0xFF00);
    tft.drawLine(430,20,430,60,0xFF00);


    Draw();
}
