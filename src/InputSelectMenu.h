#ifndef INPUT_SELECT_MENU_H
#define INPUT_SELECT_MENU_H

#include <Mode.h>
#include <Button.h>
#include <Subsystem.h>

class InputSelectMenu : public Mode{

private:

    void Setup();

public:

    InputSelectMenu();
    ~InputSelectMenu();


    virtual void Update();
    virtual void Draw();
    virtual void Redraw();


};


#endif // INPUT_SELECT_MENU_H

