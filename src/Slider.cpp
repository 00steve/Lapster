#include "Slider.h"




Slider::Slider(Int2 topLeft,Int2 bottomRight,double slideLength) :
        Button(topLeft,bottomRight,""),
        slideLength(slideLength)
    {

    Serial.println("Created slider. YAY!");
}


void Slider::Draw(){
}
bool Slider::Pressing(){
    return false;
}
bool Slider::Dragging(){
    return false;
}
