#ifndef DRAWABLE_H
#define DRAWABLE_H


#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

#define TITLE_BACKGROUND 0x1234
#define WARNING_BACKGROUND 0xC800

#include <Screen.h>


/*impliments the tftlcd class to be used by any inheriting classes
to draw to a screen*/

class Drawable{
protected:

    static ILI9341_t3 tft;

public:

    virtual void Draw() = 0;
    static ILI9341_t3 HarwareReference(ILI9341_t3 tftReference);

};

#endif
