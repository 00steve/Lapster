#include "AlertScreen.h"


void AlertScreen::Setup(){

    Button::SetTftSettings();
    //gMeterButton = new Icon(Int2(50,0),Int2(250,155),"G-Meter",SYM_GFORCE);
    //backButton = new Icon(Int2(50,0),Int2(250,100),"Back",SYM_BACK);
}

AlertScreen::AlertScreen(){
    Setup();
    Draw();
}

AlertScreen::~AlertScreen(){
    //delete backButton;
}

void AlertScreen::Update(){
    /*
    if(Button::CheckForScreenPress()){
        if(gMeterButton->Pressing()){
            Set(MODE_G_METER);
        }

    }*/
    if(Input::AlertCount() == 0) Finished(true);
}


void AlertScreen::Draw(){
    tft.fillScreen(WARNING_BACKGROUND);

    tft.setFont(AwesomeF000_40);
    tft.setCursor(20,120);
    tft.print(SYM_WARN);

    AlertInfo* a;
    Int2 cursor = Int2(110,160 - Input::AlertCount() * 8);
    tft.setCursor(cursor.x,cursor.y);
    tft.setFont(LiberationSans_28);
    for(int i=0;i<Input::AlertCount();i++){
        a = Input::Alerts()[i];
        tft.print(a->message);
    }






    //backButton->Draw();
}


void AlertScreen::Redraw(){
    Draw();
}
