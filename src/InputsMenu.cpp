#include "InputsMenu.h"


void InputsMenu::Setup(){
    backButton = new Button(Int2(50,0),Int2(160,80),"Back");
    analogInput1Button = new Button(Int2(50,90),Int2(160,170),"Analog 1");
}


InputsMenu::InputsMenu(){
    Setup();
    Redraw();
}

InputsMenu::~InputsMenu(){
    delete backButton;
    delete analogInput1Button;
}


void InputsMenu::Draw(){
}

void InputsMenu::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Inputs");

    Button::SetTftSettings();

    backButton->Draw();
    analogInput1Button->Draw();
}

void InputsMenu::Update(){
    if(Button::CheckForScreenPress()){
        if(backButton->Pressing()){
            Set(MODE_SETTINGS);
        }
        if(analogInput1Button->Pressing()){
            Serial.println("Switch to analog input edit menu");
            Set(MODE_ANALOG_INPUT_MENU_1);
        }
    }

    Draw();
}
