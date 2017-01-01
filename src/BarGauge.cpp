#include "BarGauge.h"


BarGauge::BarGauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType) :
    Gauge(topLeft,bottomRight,inputType){
    currentVal = DataStreamMinMap(0);
}

void BarGauge::Update(){

}

void BarGauge::Draw(){
    lastVal = currentVal;
    currentVal = (int)Map(DataStreamValue(0),DataStreamMinMap(0),DataStreamMaxMap(0),0,Size().y-graphPadding*2);

    /*
    if(currentVal > lastVal){
        tft.fillRect(TopLeft().x+lastVal,TopLeft().y,currentVal-lastVal,10,0xFFFF);
    } else {
        tft.fillRect(TopLeft().x+currentVal,TopLeft().y,lastVal-currentVal,10,0x0000);
    }*/



    Int2 centerBottom = Int2(Center().x-barWidth-graphPadding,BottomRight().y-graphPadding);

    if(currentVal > lastVal){
        tft.fillRect(centerBottom.x,centerBottom.y-currentVal,barWidth,currentVal-lastVal,0xFFFF);
    } else {
        tft.fillRect(centerBottom.x,centerBottom.y-lastVal,barWidth,lastVal-currentVal,0x0000);
    }
    //Serial.println(Center().x);

}

void BarGauge::Redraw(){
    //recalculate scales
    barWidth = Size().x * .2;

    //draw min marker
    tft.drawFastVLine(TopLeft().x,TopLeft().y,Size().y,0x00FF);
    //draw max marker
    tft.drawFastVLine(BottomRight().x,TopLeft().y,Size().y,0x00FF);

    tft.setFont(LiberationSans_12);
    Int2 maxPos = Int2(Center().x,TopLeft().y+graphPadding-6);
    tft.setCursor(maxPos.x,maxPos.y);
    tft.print(DataStreamMaxMap(0));

    /*
    Int2 centerRight = BottomRight();
    centerRight.x -= Size().x * .25;
    centerRight.y -= 10;
    tft.setCursor(centerRight.x,centerRight.y);
    tft.print(DataStreamMaxMap(0));
    */

    //reset the last val as the min so the whole bar is redrawn
    currentVal = DataStreamMinMap(0);

}
