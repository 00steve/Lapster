#include "EmptyGauge.h"


EmptyGauge::EmptyGauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType) :
    Gauge(topLeft,bottomRight,inputType) {
}

void EmptyGauge::Draw(){

}

void EmptyGauge::Redraw(){
    tft.drawRect(TopLeft().x,TopLeft().y,BottomRight().x-TopLeft().x,BottomRight().y-TopLeft().y,0xFFFF);
    tft.setFont(LiberationSans_12);
    Int2 center = (BottomRight() + TopLeft()) /2;
    tft.setCursor(center.x-85,center.y-6);
    tft.print("Press for context menu");
}
