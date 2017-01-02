#include "DashboardWidget.h"

DashboardWidget::DashboardWidget(Int2 topLeft, Int2 bottomRight,unsigned short gaugeType,unsigned short inputType):
        Button(topLeft,bottomRight,""),
        gauge(NULL) {
    this->inputType = inputType;
    GaugeType(gaugeType);
}

unsigned short DashboardWidget::GaugeType(unsigned short newGaugeType){
    if(gauge){
        delete gauge;
    }
    switch(newGaugeType){
    case GAUGE_TYPE_EMPTY:
        gauge = new EmptyGauge(TopLeft(),BottomRight(),inputType);
        break;
    case GAUGE_TYPE_BAR:
        gauge = new BarGauge(TopLeft(),BottomRight(),inputType);
        break;
    }
    return newGaugeType;
}

unsigned short DashboardWidget::InputType(unsigned short newInputType){
    return newInputType;
}

void DashboardWidget::Update(){

}

void DashboardWidget::Draw(){
    gauge->Draw();
}

void DashboardWidget::Redraw(){
    gauge->Redraw();
}

Int2 DashboardWidget::Size(Int2 newSize){
    bottomRight.x = topLeft.x + newSize.x;
    bottomRight.y = topLeft.y + newSize.y;
    if(gauge) gauge->Size(newSize);
    return newSize;
}
Int2 DashboardWidget::Position(Int2 newPosition){
    bottomRight += newPosition - topLeft;
    topLeft = newPosition;
    if(gauge) gauge->Position(newPosition);
    return newPosition;
}
Int2 DashboardWidget::Size(){return bottomRight - topLeft; }
Int2 DashboardWidget::Position(){ return topLeft; }
