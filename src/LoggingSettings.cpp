#include "LoggingSettings.h"



LoggingSettings::LoggingSettings(){
    Redraw();
}

LoggingSettings::~LoggingSettings(){
}


void LoggingSettings::Draw(){
}

void LoggingSettings::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Logging Settings");

    Button::SetTftSettings();
    backButton.Draw();

}

void LoggingSettings::Update(){
    if(Button::CheckForScreenPress()){
        if(backButton.Pressing()){
            Set(MODE_SETTINGS);
        }
    }
}
