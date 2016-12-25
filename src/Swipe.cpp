#include "Swipe.h"


int Swipe::direction = SWIPE_NONE;
int Swipe::state = 0;
Int2 Swipe::screenSize = Int2(SCREEN_SIZE_X,SCREEN_SIZE_Y);
Int2 Swipe::startTouchPoint = Int2(0,0);
Int2 Swipe::endTouchPoint = Int2(0,0);
bool Swipe::pressingScreen = false;
bool Swipe::waitForDepress = false;




bool Swipe::Swiped(){
    switch(state){
    case 0:
        if(Touch::Pressing()){
            startTouchPoint = Touch::Position();
            state = 2;
        }
        break;
    case 2:
        if(Touch::Pressing()){
            endTouchPoint = Touch::Position();
        } else {
            state =5;
        }
        break;
    case 5:
        state = 0;
        Int2 dir = endTouchPoint - startTouchPoint;
        if(sqrt(dir.x*dir.x + dir.y*dir.y) < 100){
            direction = SWIPE_NONE;
        } else if(abs(dir.x) > abs(dir.y)){
            direction = dir.x > 0 ? SWIPE_RIGHT : SWIPE_LEFT;
        } else {
            direction = dir.y > 0 ? SWIPE_DOWN : SWIPE_UP;
        }
        return true;

    }
    return false;
}

int Swipe::LastDirection(){
    return direction;
}
