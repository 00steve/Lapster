#ifndef SWIPE_H
#define SWIPE_H

#include <Int2.h>
#include <Touch.h>

#define SWIPE_LEFT 0
#define SWIPE_RIGHT 1
#define SWIPE_TOP 2
#define SWIPE_BOTTOM 3




class Swipe{
private:
    int direction;
    int state;

    static Int2 screenSize;
    static Int2 touchPoint;
    static bool pressingScreen;
    static bool waitForDepress;

public:
    Swipe(int direction);

    bool Swiped();

};




#endif
