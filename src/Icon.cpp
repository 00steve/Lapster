#include "Icon.h"


void Icon::Draw(){

    Int2 area = bottomRight - topLeft;

    Int2 it = Int2((text.length()*8 > 48 ? text.length()*8 : 48),70);

    Int2 off = area - it;

    tft.fillRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,backgroundColor);
    tft.setCursor(topLeft.x+off.x*.5+(it.x-48)*.5,topLeft.y+off.y*.5-8);
    tft.setFont(AwesomeF000_40);
    tft.print(icon);

    tft.setFont(LiberationSans_12);
    tft.setCursor(topLeft.x+off.x*.5,topLeft.y+off.y*.5+58);
    tft.print(text);
}
