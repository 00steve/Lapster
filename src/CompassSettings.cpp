#include "CompassSettings.h"



void CompassSettings::Setup(){
    initVec = Compass::DirectionVector();
    ftime = Subsystem::timer.Milliseconds();
}


CompassSettings::CompassSettings(){
    Setup();
    Redraw();
}


void CompassSettings::Update(){

    if(Button::CheckForScreenPress()){
        if(backButton.Pressing()){
            Set(MODE_SETTINGS);
        }
    }

    /*maths,
    the beginning of a dead reckoning system*/

    if(Subsystem::timer.Milliseconds()-ftime > 50){
        Draw();
        ftime += 50;
    }
}


void CompassSettings::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Compass");

    Button::SetTftSettings();


    backButton.Draw();
}

void CompassSettings::Draw(){
    //tft.fillRect(200,0,100,100,0x0000);
    //Double3 dv = Compass::DirectionVector();


    //tft.drawLine(250,50,dv.Y*50+250,dv.X*50+50,0x0000);
    Double3 up = Double3(0,0,1);
    double initW = -1*acos(initVec*up);
    double currW = -1*acos(Compass::DirectionVector()*up);
    Quaternion diff = Quaternion(initVec,initW).GetDelta(Quaternion(Compass::DirectionVector(),currW));


    tft.drawLine(250,50,f.Y*50+250,f.X*50+50,0x0000);
    tft.fillCircle(f.Y*50+250,f.X*50+50, 3, 0x0000);
    f = diff.GetForwardVector().Normalize();
    tft.drawLine(250,50,f.Y*50+250,f.X*50+50,0xF800);
    tft.fillCircle(f.Y*50+250,f.X*50+50, 3, 0xF800);


    tft.drawLine(250,50,u.Y*50+250,u.X*50+50,0x0000);
    tft.fillCircle(u.Y*50+250,u.X*50+50, 3, 0x0000);
    u = diff.GetUpVector().Normalize();
    tft.drawLine(250,50,u.Y*50+250,u.X*50+50,0x07E0);
    tft.fillCircle(u.Y*50+250,u.X*50+50, 3, 0x07E0);


    tft.drawLine(250,50,r.Y*50+250,r.X*50+50,0x0000);
    tft.fillCircle(r.Y*50+250,r.X*50+50, 3, 0x0000);
    r = diff.GetRightVector().Normalize();
    tft.drawLine(250,50,r.Y*50+250,r.X*50+50,0x001F);
    tft.fillCircle(r.Y*50+250,r.X*50+50, 3, 0x001F);
    //tft.drawLine()

}
