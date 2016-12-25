#ifndef CHECK_BOX_H
#define CHECK_BOX_H

#include <Button.h>

class Checkbox : public Button{



    int *minValue;
    int *maxValue;
    bool *value;
    int displayOffset;
    float displayScale;
    bool oldValue;

public:

    Checkbox(Int2 topLeft,Int2 bottomRight,String text,bool defaultValue);

    void Draw();

    void DrawCheck();


    virtual bool Pressing();

    bool SetValue(bool value);

    bool GetValue();

};


#endif
