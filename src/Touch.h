#ifndef TOUCH_H
#define TOUCH_H

#include "Int2.h"
#include <Wire.h>
#include <Input.h>

#ifndef SCREEN_SIZE_X
    #define SCREEN_SIZE_X 480
#endif // SCREEN_SIZE_X
#ifndef SCREEN_SIZE_Y
    #define SCREEN_SIZE_Y 320
#endif // SCREEN_SIZE_Y

#define touchYMPin A8
#define touchXPPin A9
#define touchYPPin A6
#define touchXMPin A7


class Touch : public Input{

private:

    static int pressureRaw;
    static Int2 raw;
    static int rxplate;

    static Int2 screenSize;
    static Int2 screenMin;
    static Int2 screenMax;

    static void readPressureFromScreen();
    static void readYFromScreen();
    static void readXFromScreen();

    static float pressure;
    static Int2 position;
    static Int2 smoothPosition;

    static int minPressure;

protected:
    virtual void SetTilt(Double3 tilt);


public:
    virtual void Setup();
    virtual String StatusString();
    virtual void Update();
    virtual String Label();

    static float Pressure();
    static Int2 Position();
    static Int2 SmoothPosition();
    static bool Pressing();
    static void ResetSmoothPosition();

};






#endif
