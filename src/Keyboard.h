#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Mode.h>
#include <Button.h>
#include <Timer.h>



class Keyboard : public Mode{
private:

    String *value;
    int valueX;
    int valueY;

    Button *backButton;
    Button *delButton;
    Button *spaceButton;

    Button *aButton;
    Button *bButton;
    Button *cButton;
    Button *dButton;
    Button *eButton;
    Button *fButton;
    Button *gButton;
    Button *hButton;
    Button *iButton;
    Button *jButton;
    Button *kButton;
    Button *lButton;
    Button *mButton;
    Button *nButton;
    Button *oButton;
    Button *pButton;
    Button *qButton;
    Button *rButton;
    Button *sButton;
    Button *tButton;
    Button *uButton;
    Button *vButton;
    Button *wButton;
    Button *xButton;
    Button *yButton;
    Button *zButton;

    Timer timer;
    unsigned long blinkInterval;
    bool blinker;
    unsigned int maxLength;


    void Setup();

public:

    Keyboard(String *value,short maxLength);

    ~Keyboard();


    void Update();


    void Draw();

    void DrawDel();

    void DrawChars(unsigned int startingIndex);


    void Redraw();

};
#endif
