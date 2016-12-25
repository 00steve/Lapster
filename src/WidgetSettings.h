#ifndef WIDGET_SETTINGS_H
#define WIDGET_SETTINGS_H

#include <Mode.h>
#include <Button.h>
#include <Swipe.h>
#include <Timer.h>
#include <DashboardWidget.h>



class WidgetSettings : public Mode{

private:
    DashboardWidget* widget;

    Button backButton = Button(Int2(50,0),Int2(160,80),"Back");

    void Setup();

public:

    WidgetSettings(DashboardWidget* widget);
    ~WidgetSettings();


    virtual void Update();
    virtual void Draw();
    virtual void Redraw();


};








#endif // WIDGET_SETTINGS_H
