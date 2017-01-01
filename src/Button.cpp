#include "Button.h"

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
//TouchScreen Button::touchScreen = TouchScreen(XP, YP, XM, YM, 300);
Int2 Button::touchPoint = Int2(0,0);
bool Button::pressing = false;
bool Button::dragging = false;
bool Button::pressingScreen = false;
bool Button::pressedScreen = false;
bool Button::waitForDepress = false;
Int2 Button::dragStartPoint = Int2(0,0);
Int2 Button::dragEndPoint = Int2(0,0);

Timer Button::timer = Timer();
long Button::pressStartTime = 0;
long Button::pressDuration = 0;

int Button::backgroundColor = 0x4224;
int Button::activeBackgroundColor = 0xFFFF;
int Button::disabledBackgroundColor = 0x3113;
int Button::textColor = 0xFFFF;
int Button::activeTextColor = 0x0000;
int Button::borderRadius = 7;
int Button::textSize = 2;

Int2 Button::touchScreenTopLeft = Int2(0,0);
Int2 Button::touchScreenBottomRight = Int2(0,0);



void Button::Update(){
    pressing = Touch::Pressing();
    if(pressing && !waitForDepress){
        pressStartTime = timer.Milliseconds();
    }
    pressedScreen = (!pressing && waitForDepress);
    if(pressedScreen){
        pressDuration = 0;
        //Serial.println("[pressed screen]");
    }
    /*stays true while screen is being pressed and it itself
    is also true. Once it is no longer true, it stays untrue
    until the pressing screen boolean is true*/
    waitForDepress = (pressing && waitForDepress);
    if(waitForDepress){
        pressDuration = timer.Milliseconds() - pressStartTime;
    }
    pressingScreen = (pressing && !waitForDepress);

    if(pressingScreen){
        touchPoint = Touch::Position();
        waitForDepress = true;
    }
}

Button::Button(Int2 topLeft,Int2 bottomRight,String text,Int2 textOffset) :
            topLeft(topLeft),
            bottomRight(bottomRight),
            text(text),
            textOffset(textOffset),
            pressed(false),
            disabled(false)
            {
    }

Button::Button(Int2 topLeft,Int2 bottomRight,String text) :
            topLeft(topLeft),
            bottomRight(bottomRight),
            text(text),
            textOffset(Int2(10,(bottomRight.y-topLeft.y)*.5-textSize*3.5)),
            pressed(false),
            disabled(false)
            {
    }


Button::~Button(){
}

void Button::Draw(){
        //tft.fillRoundRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,borderRadius,backgroundColor);
        tft.fillRect(topLeft.x,topLeft.y,bottomRight.x-topLeft.x,bottomRight.y-topLeft.y,backgroundColor);
        tft.setCursor(topLeft.x+textOffset.x,topLeft.y+textOffset.y);
        tft.print(text);
    }

bool Button::Pressing(){
    return pressingScreen &&
        !disabled &&
        touchPoint.x >= topLeft.x &&
        touchPoint.x <= bottomRight.x &&
        touchPoint.y >= topLeft.y &&
        touchPoint.y <= bottomRight.y;
}

bool Button::Holding(){
    bool holding = waitForDepress && pressDuration > 1000 &&
        !disabled &&
        touchPoint.x >= topLeft.x &&
        touchPoint.x <= bottomRight.x &&
        touchPoint.y >= topLeft.y &&
        touchPoint.y <= bottomRight.y;
    //go right to not pressed screen so holding, having another button
    //get displayed underneath the holding one (that only needs to be
    //pressed
    if(holding){
        ResetPressingAfterHolding();
    }
    return holding;
}


void Button::ResetPressingAfterHolding(){
        waitForDepress = false;
        pressedScreen = false;
}

bool Button::Pressed(){
    return pressedScreen && pressDuration <= 1000 &&
        !disabled &&
        touchPoint.x >= topLeft.x &&
        touchPoint.x <= bottomRight.x &&
        touchPoint.y >= topLeft.y &&
        touchPoint.y <= bottomRight.y;
}

bool Button::Disable(){
    disabled = true;
    return disabled;
}
bool Button::Enable(){
    disabled = false;
    return disabled;
}

void Button::SetupButton(){
    //touchScreenTopLeft = Int2(EepromStorage::readShort(TOUCHSCREEN_X_MIN_SHORT),EepromStorage::readShort(TOUCHSCREEN_Y_MIN_SHORT));
    //touchScreenBottomRight = Int2(EepromStorage::readShort(TOUCHSCREEN_X_MAX_SHORT),EepromStorage::readShort(TOUCHSCREEN_Y_MAX_SHORT));
};


/*sets the tft settings to draw a button. This is
broken out as a seperate function so it can be called
once, then several buttons can be drawn, without having
to call the same code over and over again.*/
void Button::SetTftSettings(){
    tft.setTextColor(textColor);
    tft.setTextSize(textSize);
    tft.setFont(LiberationSans_12);
}
void Button::SetActiveTftSettings(){
    tft.setTextColor(activeTextColor);
    tft.setTextSize(textSize);
    tft.setFont(LiberationSans_12);
}

String Button::setText(String text){
    return this->text = text;
}

bool Button::CheckForScreenPress(){
    Update();
    return pressingScreen;
}

bool Button::CheckForScreenPressed(){
    Update();
    return pressedScreen;
}

bool Button::CheckForScreenDrag(){
    bool oldDragging = dragging;
    dragging = Touch::Pressing();
    if(dragging && !oldDragging){
        Touch::ResetSmoothPosition();
        dragStartPoint = dragEndPoint = Touch::SmoothPosition();
        //Serial.println("start dragging screen");
    } else if(dragging && oldDragging){
        dragEndPoint = Touch::SmoothPosition();
    } else if(!dragging && oldDragging){
        //Serial.println("stop dragging screen");
    }
    return dragging || oldDragging;
}

bool Button::CheckForScreenHolding(){
    Update();
    return waitForDepress && pressDuration > 1000;
}

bool Button::PressingScreen(){
    return pressingScreen;
}
bool Button::HoldingScreen(){
    return waitForDepress;
}

void Button::WaitForDepress(){
    waitForDepress = true;
}

Int2 Button::TopLeft(){ return topLeft; }
Int2 Button::BottomRight(){ return bottomRight; }





