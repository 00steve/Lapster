#include "WidgetSettings.h"


WidgetSettings::WidgetSettings(DashboardWidget* widget){
    this->widget = widget;
}

WidgetSettings::~WidgetSettings(){
}


void WidgetSettings::Update(){

    if(Swipe::Swiped()){
        switch(Swipe::LastDirection()){
        case SWIPE_UP:
            break;
        case SWIPE_DOWN:
            Finished(true);
            return;
            //Finished(true);
            //break;
        case SWIPE_RIGHT:
            break;
        case SWIPE_LEFT:
            break;
        }
    }

    if(Button::CheckForScreenPress()){
        //if(backButton.Pressing()){
        //    Finished(true);
        //}
        //if(analogInput1Button->Pressing()){
         //   Serial.println("Switch to analog input edit menu");
         //   Set(MODE_ANALOG_INPUT_MENU_1);
        //}
    }
    Draw();
}

void WidgetSettings::Draw(){

}

void WidgetSettings::Redraw(){

    tft.fillScreen(0x0000);
    DrawTitle("Widget Settings");

    Button::SetTftSettings();

    backButton.Draw();
}
