#include <Screen.h>

ILI9341_t3 Screen::tft = ILI9341_t3(SCREEN_CS_PIN, SCREEN_DC_PIN);


bool Screen::Setup(){

    // Use hardware SPI (#13, #12, #11) and the above for CS/DC
    tft.begin();
    tft.setRotation( 1 );
    tft.fillScreen(ILI9341_BLACK);

     tft.setFont(AwesomeF000_40);
     tft.setCursor(86,170);
    tft.print(SYM_LAP);
    tft.print(SYM_TIME);
    tft.print(SYM_WARN);
    tft.print(SYM_GFORCE);
    tft.print(SYM_YES);
    tft.print(SYM_NO);


     //tft.println(" !\"#$%&'()@`~{}[]+=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.,<>?/\\;:\t\n*-_|\r\v\a\b\f\'\"\x0000\x0001\x0002");

     tft.setTextColor (ILI9341_WHITE);   // <--- Should be white background
     tft.setFont(Georgia_48_Italic);
     tft.setCursor(35,90);
     tft.println("Lapsterbator");
     tft.setFont(LiberationSans_12);
     tft.setCursor(360,150);
     tft.print("v0.91");

    return true;
};


ILI9341_t3 Screen::HardwareReference(){
    return tft;
}

void Screen::Clear(int color){
    tft.fillScreen(color);
}

void Screen::Print(ILI9341_t3_font_t font,int color,Int2 cursor,String text){
     tft.setTextColor (color);   // <--- Should be white background
     tft.setFont(font);
     tft.setCursor(cursor.x,cursor.y);
     tft.println(text);
}


void Screen::FillRect(int xmin,int ymin,int xmax,int ymax,int color){
    tft.fillRect(xmin,ymin,xmax-xmin,ymax-ymin,color);
}
