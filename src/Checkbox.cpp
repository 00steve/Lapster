#include "Checkbox.h"


Checkbox::Checkbox(Int2 topLeft,Int2 bottomRight,String text,bool defaultValue) :
            Button(topLeft,bottomRight,text,Int2(10,(bottomRight.y-topLeft.y)*.5-textSize*3.5)),
            minValue(NULL),
            maxValue(NULL),
            value(new bool(defaultValue)),
            displayOffset(0),
            displayScale(1)
            {
    }

void Checkbox::Draw(){
    tft.drawRoundRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,borderRadius,backgroundColor);
    tft.setCursor(bottomRight.x+textOffset.x,topLeft.y+textOffset.y);
    tft.print(text);
    DrawCheck();
}

void Checkbox::DrawCheck(){
    tft.fillRoundRect(topLeft.x+5,topLeft.y+5,bottomRight.x-topLeft.x-10,bottomRight.y-topLeft.y-10,borderRadius-2,(*value ? 0xffff : 0x0000));
}


bool Checkbox::Pressing(){

    oldValue = *value;
    if(pressingScreen && !disabled){
        if( touchPoint.x >= topLeft.x &&
            touchPoint.x <= bottomRight.x &&
            touchPoint.y >= topLeft.y &&
            touchPoint.y <= bottomRight.y){
            *value = !(*value);
            DrawCheck();
            waitForDepress = true;
            return true;

        }
    }

    return false;
}

bool Checkbox::SetValue(bool value){
    return *this->value = value;
}

bool Checkbox::GetValue(){
    return *value;
}

