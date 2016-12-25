#include "Confirm.h"


Confirm::Confirm(String message,bool* yea) :
        message(message),
        yea(yea){
    continueButton = new Icon(Int2(10,160),Int2(235,310),"Continue",SYM_YES);
    cancelButton = new Icon(Int2(245,160),Int2(470,310),"Cancel",SYM_NO);
}

Confirm::~Confirm(){
    delete continueButton;
    delete cancelButton;
}

void Confirm::Redraw(){
    Draw();
}
void Confirm::Update(){
    if(Button::CheckForScreenPress()){
        if(continueButton->Pressing()){
            *yea = true;
            Finished(true);
        }else if(cancelButton->Pressing()){
            *yea = false;
            Finished(true);
        }

    }
}


void Confirm::Draw(){
    tft.fillScreen(0x0000);
    //tft.fillRect(0,0,480,200,TITLE_BACKGROUND);
    tft.setFont(LiberationSans_24);
    tft.setCursor(0,0);
    tft.setTextColor(0xFFFF);
    tft.print(message);
    tft.setFont(LiberationSans_12);

    continueButton->Draw();
    cancelButton->Draw();
}
