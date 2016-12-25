#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H


#include <Mode.h>
#include <Icon.h>
#include <Confirm.h>
#include <Subsystem.h>

class Diagnostics : public Mode{
private:


    //Button* gMeterButton;
    Button backButton = Icon(Int2(50,0),Int2(250,100),"Back",SYM_BACK);
    Button resetButton = Icon(Int2(50,110),Int2(250,210),"Reset Settings",SYM_RESET);

    void Setup();

    /*flag to store if reset has been confirmed*/
    bool confirmReset;

public:

    Diagnostics();
    ~Diagnostics();

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();

};




#endif
