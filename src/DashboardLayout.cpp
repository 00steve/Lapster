#include "DashboardLayout.h"


void DashboardLayout::Setup(){
    switch(layoutID){
    case LAYOUT_SINGLE:
        Serial.println("use default single widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(470,310));
        widgetCount = 1;
        break;
    case LAYOUT_SIDE_BY_SIDE:
        Serial.println("use default single widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(235,310));
        widget[1] = new DashboardWidget(Int2(245,10),Int2(470,310));
        widgetCount = 2;
        break;

    case LAYOUT_QUADS:
        Serial.println("use default single widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(235,155));
        widget[1] = new DashboardWidget(Int2(245,10),Int2(470,155));
        widget[2] = new DashboardWidget(Int2(10,165),Int2(235,310));
        widget[3] = new DashboardWidget(Int2(245,165),Int2(470,310));
        widgetCount = 4;
        break;
    }
}




DashboardLayout::DashboardLayout(int layoutID) :
        layoutID(layoutID){
    Setup();
    //stuff in the layout
}

DashboardLayout::~DashboardLayout(){
    int i = widgetCount;
    while(i --> 0){
        delete widget[i];
    }
}





void DashboardLayout::Redraw(){
    int i=widgetCount;
    while(i --> 0){
        widget[i]->Redraw();
    }
}


void DashboardLayout::Draw(){


}
