#include "Mode.h"



void Mode::DrawTitle(String title){
    tft.fillRect(0,0,40,320,TITLE_BACKGROUND);
    tft.setRotation(2);
    tft.setFont(LiberationSans_28);
    tft.setCursor(5,445);
    tft.print(title);
    tft.setRotation(1);
}


void Mode::Set(int newMode){
    finished = true;
    nextMode = newMode;
}


bool Mode::Finished(bool finished){
    return this->finished = finished;
}
bool Mode::Finished(){
    return finished;
}

void Mode::PushState(Mode *nextState){
    this->nextState = nextState;
}

bool Mode::HasPushState(){
    return nextState;
}

Mode* Mode::PushState(){
    Mode *tmp = nextState;
    nextState = NULL;
    return tmp;
}

bool Mode::PopState(){
    return finished;
}


int Mode::NextMode(){
    return nextMode;
}

