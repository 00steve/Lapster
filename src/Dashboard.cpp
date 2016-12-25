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

    if(Swipe::Swiped()){
        switch(Swipe::LastDirection()){
        case SWIPE_UP:
            break;
        case SWIPE_DOWN:
            Set(MODE_MAIN_MENU);
            return;
            //Finished(true);
            //break;
        case SWIPE_RIGHT:
            break;
        case SWIPE_LEFT:
            break;
        }
    }

    if(dashboardLayout){
        dashboardLayout->Update();
        if(dashboardLayout->ShouldEditWidget()){
            PushState(new WidgetSettings(dashboardLayout->EditWidget()));
        }
    }
}

void Dashboard::Redraw(){
    tft.fillScreen(0x0000);
    if(dashboardLayout) dashboardLayout->Redraw();

    Draw();
}

void Dashboard::Draw(){

}
