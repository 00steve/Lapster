#include "DashboardWidget.h"






DashboardWidget::DashboardWidget(Int2 topLeft, Int2 bottomRight):
        Button(topLeft,bottomRight,"") {
    //stuff in the class
}




void DashboardWidget::Update(){

}



void DashboardWidget::Draw(){


}

void DashboardWidget::Redraw(){
    tft.drawRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,0xFFFF);
    tft.setFont(LiberationSans_12);
    Int2 center = (bottomRight + topLeft) /2;
    tft.setCursor(center.x-85,center.y-6);
    tft.print("Press for context menu");
}
