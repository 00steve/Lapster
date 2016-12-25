#include "Swipe.h"



Int2 Swipe::screenSize = Int2(SCREEN_SIZE_X,SCREEN_SIZE_Y);
Int2 Swipe::touchPoint = Int2(0,0);
bool Swipe::pressingScreen = false;
bool Swipe::waitForDepress = false;


Swipe::Swipe(int direction) :
            direction(direction),
            state(0)
        {

}


bool Swipe::Swiped(){/*
    if(!pressingScreen && state == 0){
        pressingScreen = Touch::Pressing();
        state = 1;
    }



    switch(state){
    case 1:
        if(Touch::Pressing()){

        }
        break;
    default:
        Serial.println("restart swipe");
    }
*/
    return false;
}
