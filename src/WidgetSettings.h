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
    Int2 widgetSize = Int2(0,0);
    Int2 widgetPosition = Int2(0,0);

    Button inputButton = Button(Int2(220,10),Int2(340,130),"Input");
    Button something = Button(Int2(350,10),Int2(470,130),"Something");

    //Button backButton = Button(Int2(50,0),Int2(160,80),"Back");

    void Setup();

public:

    WidgetSettings(DashboardWidget* currentWidget);
    ~WidgetSettings();


    virtual void Update();
    virtual void Draw();
    virtual void Redraw();


};








#endif // WIDGET_SETTINGS_H
