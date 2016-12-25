#include "SettingsMenu.h"


void SettingsMenu::CustomInput(){
}

SettingsMenu::SettingsMenu(){
    Redraw();
}

SettingsMenu::~SettingsMenu(){
}

void SettingsMenu::Update(){
    if(Button::CheckForScreenPress()){
        if(backButton.Pressing()){
            Set(MODE_MAIN_MENU);
        }
        if(inputsButton.Pressing()){
            Set(MODE_INPUTS_MENU);
        }
        if(gpsButton.Pressing()){
            Set(MODE_GPS_SETTINGS);
        }
        if(compassButton.Pressing()){
            Set(MODE_COMPASS_SETTINGS);
        }
        if(loggingButton.Pressing()){
            Set(MODE_LOGGING_SETTINGS);
        }
        if(storageButton.Pressing()){
            Set(MODE_STORAGE_SETTINGS);
        }
        if(accelerometerButton.Pressing()){
            Set(MODE_ACCELEROMETER_SETTINGS);
        }
        if(gyrometerButton.Pressing()){
            Set(MODE_GYROMETER_SETTINGS);
        }
    }

    Draw();

}



void SettingsMenu::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Settings");
    Button::SetTftSettings();

    backButton.Draw();
    inputsButton.Draw();
    gpsButton.Draw();
    compassButton.Draw();
    loggingButton.Draw();
    storageButton.Draw();
    accelerometerButton.Draw();
    gyrometerButton.Draw();

    Draw();
}

void SettingsMenu::Draw(){
}
