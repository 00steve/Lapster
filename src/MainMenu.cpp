#include "MainMenu.h"



void MainMenu::Setup(){
}

MainMenu::MainMenu(){
    Setup();
    Draw();
}

MainMenu::~MainMenu(){
}

void MainMenu::Update(){
    if(Button::CheckForScreenPress()){
        if(settingsButton.Pressing()){
            Set(MODE_SETTINGS);
        }
        if(dataLoggerButton.Pressing()){
            Set(MODE_DATA_LOGGER);
        }
        if(dashboardButton.Pressing()){
            Set(MODE_DASHBOARD);
        }
    }
}


void MainMenu::Draw(){
    tft.fillScreen(0x0000);
    DrawTitle("Lapsterbator");
    gMeterButton.Draw();
    dataLoggerButton.Draw();
    zSixtyButton.Draw();
    settingsButton.Draw();
    dashboardButton.Draw();
}


void MainMenu::Redraw(){
    Draw();
}


