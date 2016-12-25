#ifndef NUMBER_SPINNER_H
#define NUMBER_SPINNER_H

#include <Button.h>
#include <math.h>

class NumberSpinner : public Button{
private:
    double* value;
    double startValue;
    double endValue;
    double minimum;
    double maximum;

public:

    NumberSpinner(Int2 topLeft,Int2 bottomRight,double* value,double minimum,double maximum);

    virtual void Draw();
    virtual bool Pressing();
    bool Dragging();

};

#endif
