#include "WidgetSettings.h"


WidgetSettings::WidgetSettings(DashboardWidget* currentWidget){
    widget = currentWidget;
    widgetPosition = widget->Position();
    widgetSize = widget->Size();
    widget->Size(Int2(160,160));
    widget->Position(Int2(50,80));

}

WidgetSettings::~WidgetSettings(){
}


void WidgetSettings::Update(){

    if(Swipe::Swiped()){
        switch(Swipe::LastDirection()){
        case SWIPE_DOWN:
            widget->Size(widgetSize);
            widget->Position(widgetPosition);
            Finished(true);
            return;
        }
    }

    if(Button::CheckForScreenPressed()){
        if(inputButton.Pressed()){
            Serial.println("pressed");
        }
        if(widget->Pressed()){
            Serial.println("switch widget");
        }
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
    widget->Draw();
}

void WidgetSettings::Redraw(){

    tft.fillScreen(0x0000);
    DrawTitle("Widget Settings");

    Button::SetTftSettings();

    widget->Redraw();

    inputButton.Draw();
    something.Draw();

    //backButton.Draw();
}
