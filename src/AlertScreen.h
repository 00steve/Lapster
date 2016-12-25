#ifndef ALERT_SCREEN_H
#define ALERT_SCREEN_H

#include <Mode.h>
#include <Icon.h>



class AlertScreen : public Mode{
private:


    //Button* gMeterButton;
    Button* backButton;


    void Setup();

public:

    AlertScreen();
    ~AlertScreen();

    void Update();
    void Draw();
    void Redraw();

};

#endif
