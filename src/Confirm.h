#ifndef CONFIRM_SCREEN_H
#define CONFIRM_SCREEN_H


#include <Mode.h>
#include <Icon.h>


class Confirm : public Mode{
private:

    String message;
    bool* yea;

    Icon* continueButton;
    Icon* cancelButton;

public:
    Confirm(String message,bool* yea);
    ~Confirm();

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();

};

#endif
