#ifndef COMPASS_SETTINGS_H
#define COMPASS_SETTINGS_H


#include <Mode.h>
#include <Subsystem.h>
#include <Quaternion.h>

class CompassSettings : public Mode{
private:

    Button backButton = Button(Int2(50,0),Int2(160,80),"Back");

    Double3 initVec = Double3(0,1,0);

    Double3 f = Double3(0,0,0);
    Double3 u = Double3(0,0,0);
    Double3 r = Double3(0,0,0);
    long ftime = 0;

    void Setup();



public:

    CompassSettings();

    virtual void Update();
    virtual void Redraw();
    void Draw();



};





#endif
