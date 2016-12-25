#include "Diagnostics.h"




void Diagnostics::Setup(){

    //Button::SetTftSettings();
    //gMeterButton = new Icon(Int2(50,0),Int2(250,155),"G-Meter",SYM_GFORCE);

}

Diagnostics::Diagnostics() :
        confirmReset(false)
        {
    Setup();
    Draw();
}

Diagnostics::~Diagnostics(){
    //delete backButton;
    //delete resetButton;
    //delete gMeterButton;
}

void Diagnostics::Update(){
    if(confirmReset){
        Serial.println("System is being reset to factory settings");
        Subsystem::FactoryReset();
        confirmReset = false;
        Set(MODE_MAIN_MENU);
    }

    if(Button::CheckForScreenPress()){
        if(backButton.Pressing()){
            Serial.println("change from diagnostics screen");
            Set(MODE_MAIN_MENU);
        }
        if(resetButton.Pressing()){
            PushState(new Confirm(String("Are you sure you want to reset to factory default? Any custom input settings, or other types of custom settings will be lost."),&confirmReset));
        }
    }



}


void Diagnostics::Draw(){
    tft.fillScreen(0x0000);
    DrawTitle("Diagnostics");

    Button::SetTftSettings();
    backButton.Draw();
    resetButton.Draw();
}


void Diagnostics::Redraw(){
    Draw();
}
