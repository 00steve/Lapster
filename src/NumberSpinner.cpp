#include "NumberSpinner.h"


NumberSpinner::NumberSpinner(Int2 topLeft,Int2 bottomRight,double* value,double minimum,double maximum) :
        Button(topLeft,bottomRight,""),
        value(value),
        minimum(minimum),
        maximum(maximum) {

}


void NumberSpinner::Draw(){
    if(pressed){
        Button::SetActiveTftSettings();
        tft.fillRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,activeBackgroundColor);
    } else {
        Button::SetTftSettings();
        tft.fillRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,backgroundColor);
    }
    tft.setCursor(topLeft.x+textOffset.x,topLeft.y+textOffset.y);
    //tft.print(text);
    tft.print(*value);

}

bool NumberSpinner::Pressing(){
    bool oldPressed = pressed;
    pressed = pressingScreen &&
            !disabled &&
            touchPoint.x >= topLeft.x &&
            touchPoint.x <= bottomRight.x &&
            touchPoint.y >= topLeft.y &&
            touchPoint.y <= bottomRight.y;
    if(!oldPressed && pressed){
        startValue = *value;
        Serial.println("Start dragging spinner");
        Draw();
    }

    return pressed;
}




bool NumberSpinner::Dragging(){
    if(pressed){
        Int2 m = dragEndPoint - dragStartPoint;
        double newValue = startValue + m.y*.01*fabs(m.x*.1+1);
        if(newValue < minimum) newValue = minimum;
        else if(newValue > maximum) newValue = maximum;

        *value = newValue;
        Serial.print(startValue);
        Serial.print(" -> ");
        Serial.println(newValue);

        Draw();
        if(!Touch::Pressing()){
            pressed = false;
            Serial.println("Finished dragging spinner");
            Draw();
        }
    }

    return true;
}
