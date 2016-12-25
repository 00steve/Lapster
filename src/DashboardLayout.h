#ifndef DASHBOARD_LAYOUT_H
#define DASHBOARD_LAYOUT_H

#include <DashboardWidget.h>


#define LAYOUT_SINGLE 1
#define LAYOUT_SIDE_BY_SIDE 2
#define LAYOUT_QUADS 4



class DashboardLayout {
private:

    int layoutID;
    DashboardWidget *widget[6];
    int widgetCount;

    void Setup();

public:

    DashboardLayout(int layoutID);
    ~DashboardLayout();


    void Draw();
    void Redraw();



};




#endif
