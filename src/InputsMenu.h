#ifndef INPUT_MENU_H
#define INPUT_MENU_H

#include <Mode.h>

class InputsMenu : public Mode{
private:

    Button *backButton;
    Button *analogInput1Button;


    void Setup();

public:

    InputsMenu();
    ~InputsMenu();

    virtual void Draw();
    virtual void Redraw();
    virtual void Update();

};





#endif
