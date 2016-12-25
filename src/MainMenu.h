
#ifndef MENU_H
#define MENU_H

#include <Mode.h>
#include <Icon.h>

class MainMenu : public Mode{
private:


    Icon gMeterButton = Icon(Int2(40,0),Int2(180,100),"G-Meter",SYM_GFORCE);
    Icon dataLoggerButton = Icon(Int2(190,0),Int2(330,100),"Data Logger",SYM_LOG);
    Button zSixtyButton = Button(Int2(340,0),Int2(480,100),"0-60 Timer");
    Icon settingsButton = Icon(Int2(40,110),Int2(180,210),"Settings",SYM_SETTINGS);
    Icon dashboardButton = Icon(Int2(190,110),Int2(330,210),"Dashboard",SYM_INFO);


    void Setup();

public:

    MainMenu();
    ~MainMenu();

    void Update();
    void Draw();
    void Redraw();

};


#endif

