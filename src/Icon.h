#ifndef ICON_BUTTON_H
#define ICON_BUTTON_H


#include <Button.h>

class Icon : public Button{
protected:

    char icon;

public:

    Icon(Int2 topLeft,Int2 bottomRight,String text,char icon) :
        Button(topLeft,bottomRight,text),
        icon(icon){
    }

    virtual void Draw();

};



#endif
