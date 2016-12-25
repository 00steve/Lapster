#include "GyrometerSettings.h"



void GyrometerSettings::Setup(){
    ftime = Subsystem::timer.Milliseconds();
}


void GyrometerSettings::Calibrate(){

}


GyrometerSettings::GyrometerSettings(){
    Setup();
    Redraw();
}


void GyrometerSettings::Update(){

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


void GyrometerSettings::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Gyrometer");

    Button::SetTftSettings();


    backButton.Draw();
}

void GyrometerSettings::Draw(){
    //backButton = new Button(Int2(50,0),Int2(160,80),"Back");
    //initVec = Gyrometer::DirectionVector();
    ftime = Subsystem::timer.Milliseconds();
}

