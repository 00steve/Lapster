#ifndef SCREEN_H
#define SCREEN_H

#include "SPI.h"
#include "ILI9341_t3.h"
#include "font_Arial.h"
#include "font_AwesomeF000.h"
#include "font_GeorgiaItalic.h"
#include "font_LiberationSans.h"
#include <Int2.h>

#define SCREEN_DC_PIN 9
#define SCREEN_CS_PIN 10


#define SYM_LAP (char)30
#define SYM_TIME (char)23
#define SYM_WARN (char)113
#define SYM_GFORCE (char)91
#define SYM_YES (char)12
#define SYM_NO  (char)13
#define SYM_BACK (char)83
#define SYM_SETTINGS (char)19
#define SYM_RESET (char)121
#define SYM_LOG (char)22
#define SYM_INFO (char)90

class Screen{
private:

    static ILI9341_t3 tft;

public:

    static bool Setup();
    static ILI9341_t3 HardwareReference();
    static void Clear(int color);
    static void Print(ILI9341_t3_font_t font,int color,Int2 cursor,String text);
    static void FillRect(int xmin,int ymin,int xmax,int ymax,int color);
};




#endif
