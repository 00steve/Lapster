#ifndef BUTTON_H
#define BUTTON_H

#include <Int2.h>
#include <Drawable.h>
#include <Touch.h>
#include <Timer.h>


class Button : public Drawable{
protected:

    Int2 topLeft;
    Int2 bottomRight;
    String text;
    Int2 textOffset;
    bool pressed;
    bool disabled;

    static Int2 touchScreenTopLeft;
    static Int2 touchScreenBottomRight;

    static Int2 touchPoint;
    static bool pressing;
    static bool dragging;
    static bool pressingScreen;
    static bool pressedScreen;
    static bool waitForDepress;
    static Int2 dragStartPoint;
    static Int2 dragEndPoint;

    static Timer timer;
    static long pressStartTime;
    static long pressDuration;

    static int backgroundColor;
    static int activeBackgroundColor;
    static int disabledBackgroundColor;
    static int textColor;
    static int activeTextColor;
    static int borderRadius;
    static int textSize;

    /*used to update the status of the button screen*/
    static void Update();


    Button(Int2 topLeft,Int2 bottomRight,String text,Int2 textOffset);

public:
    Button(Int2 topLeft,Int2 bottomRight,String text);

    virtual ~Button();

    virtual void Draw();

    virtual bool Pressing();
    virtual bool Pressed();
    virtual bool Holding();

    virtual bool Disable();
    virtual bool Enable();

    static void SetupButton();



    /*sets the tft settings to draw a button. This is
    broken out as a seperate function so it can be called
    once, then several buttons can be drawn, without having
    to call the same code over and over again.*/
    static void SetTftSettings();
    static void SetActiveTftSettings();

    String setText(String text);

    static bool CheckForScreenPress();
    static bool CheckForScreenPressed();
    static bool CheckForScreenDrag();
    static bool CheckForScreenHolding();

    static bool PressingScreen();
    static bool HoldingScreen();

    static void WaitForDepress();

};



#endif
