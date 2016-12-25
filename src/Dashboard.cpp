#include "Dashboard.h"


void Dashboard::Setup(){
    dashboardLayout = new DashboardLayout(LAYOUT_QUADS);
}


Dashboard::Dashboard(){
    Setup();
    Redraw();
}

Dashboard::~Dashboard(){
    if(dashboardLayout) delete dashboardLayout;
}


void Dashboard::Update(){
    if(Button::CheckForScreenPressed()){
        Serial.println("pressed screen");
    }
}

void Dashboard::Redraw(){
    tft.fillScreen(0x0000);
    if(dashboardLayout) dashboardLayout->Redraw();

    Draw();
}

void Dashboard::Draw(){

}
