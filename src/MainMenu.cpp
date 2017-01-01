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
    if(Button::CheckForScreenPressed()){
        if(settingsButton.Pressed()){
            Set(MODE_SETTINGS);
        }
        if(dataLoggerButton.Pressed()){
            Set(MODE_DATA_LOGGER);
        }
        if(dashboardButton.Pressed()){
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


