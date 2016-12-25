#ifndef DASHBOARD_WIDGET_H
#define DASHBOARD_WIDGET_H

#include <Int2.h>
#include <Button.h>


class DashboardWidget : public Button {
private:


public:

    DashboardWidget(Int2 topLeft,Int2 bottomRight);

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();

};


#endif
