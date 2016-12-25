#ifndef SLIDER_H
#define SLIDER_H


#include <Int2.h>
#include <Button.h>
#include <math.h>

class Slider : public Button{
private:
    double slideLength;
public:

    Slider(Int2 topLeft,Int2 bottomRight,double slideLength);

    virtual void Draw();
    virtual bool Pressing();
    bool Dragging();

};

#endif
