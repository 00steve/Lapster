#ifndef ANALOG_INPUT_MENU_H
#define ANALOG_INPUT_MENU_H

#include <Mode.h>
#include <Checkbox.h>
#include <Subsystem.h>
#include <Timer.h>
#include <Keyboard.h>
#include <NumberSpinner.h>

class AnalogInputMenu : public Mode{
private:

    AnalogInput* iRef;
    int inputId;
    String name;
    String units;
    bool changed;

    Button* backButton;
    Checkbox* enabledCheck;
    Button* nameButton;
    Button* unitsButton;
    NumberSpinner* vInMinSpinner;
    NumberSpinner* vInMaxSpinner;
    NumberSpinner* mapMinSpinner;
    NumberSpinner* mapMaxSpinner;

    Timer timer;
    double newVoltage;
    double oldVoltage;

    void Setup();

public:

    AnalogInputMenu(int inputId);
    ~AnalogInputMenu();


    void Draw();
    void Redraw();
    void Update();

};





#endif
