#include "DashboardLayout.h"


void DashboardLayout::Setup(){
    switch(layoutID){
    case LAYOUT_SINGLE:
        Serial.println("use default single widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(470,310),GAUGE_TYPE_BAR,INPUT_ANALOG1);
        widgetCount = 1;
        break;
    case LAYOUT_SIDE_BY_SIDE:
        Serial.println("use double widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(235,310),GAUGE_TYPE_EMPTY,INPUT_ANALOG1);
        widget[1] = new DashboardWidget(Int2(245,10),Int2(470,310),GAUGE_TYPE_BAR,INPUT_ANALOG1);
        widgetCount = 2;
        break;

    case LAYOUT_QUADS:
        Serial.println("use quad widget dashboard");
        widget[0] = new DashboardWidget(Int2(10,10),Int2(235,155),GAUGE_TYPE_EMPTY,INPUT_ANALOG1);
        widget[1] = new DashboardWidget(Int2(245,10),Int2(470,155),GAUGE_TYPE_BAR,INPUT_ANALOG1);
        widget[2] = new DashboardWidget(Int2(10,165),Int2(235,310),GAUGE_TYPE_EMPTY,INPUT_ANALOG1);
        widget[3] = new DashboardWidget(Int2(245,165),Int2(470,310),GAUGE_TYPE_EMPTY,INPUT_ANALOG1);
        widgetCount = 4;
        break;
    }
}




DashboardLayout::DashboardLayout(int layoutID) :
        layoutID(layoutID),
        editWidgetIndex(-1){
    Setup();
    //stuff in the layout
}

DashboardLayout::~DashboardLayout(){
    int i = widgetCount;
    while(i --> 0){
        delete widget[i];
    }
}


void DashboardLayout::Update(){
    if(Button::CheckForScreenHolding()){
        Serial.println("check for button");
        int i = widgetCount;
        while(i --> 0){
            if(widget[i]->Holding()){
                editWidgetIndex = i;
                Serial.println("edit widget");
                return;
            }
        }
    }
}


void DashboardLayout::Redraw(){
    int i=widgetCount;
    while(i --> 0){
        widget[i]->Redraw();
    }
}


void DashboardLayout::Draw(){
    int i=widgetCount;
    while(i --> 0){
        widget[i]->Draw();
    }
}

bool DashboardLayout::ShouldEditWidget(){
    return editWidgetIndex > -1;
}

DashboardWidget* DashboardLayout::EditWidget(){
    int ind = editWidgetIndex;
    editWidgetIndex = -1;
    return widget[ind];
}
