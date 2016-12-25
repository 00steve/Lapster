#ifndef SWIPE_H
#define SWIPE_H

#include <Int2.h>
#include <Touch.h>

#define SWIPE_LEFT 0
#define SWIPE_RIGHT 1
#define SWIPE_UP 2
#define SWIPE_DOWN 3
#define SWIPE_NONE 4




class Swipe{
private:
    static int direction;
    static int state;

    static Int2 screenSize;
    static Int2 startTouchPoint;
    static Int2 endTouchPoint;
    static bool pressingScreen;
    static bool waitForDepress;

public:
    static bool Swiped();

    /*use declared directions at the top of this header file.*/
    static int LastDirection();

};




#endif
