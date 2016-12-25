
#include "Drawable.h"

ILI9341_t3 Drawable::tft = ILI9341_t3(0,0);

ILI9341_t3 Drawable::HarwareReference(ILI9341_t3 tftReference){
    return tft = tftReference;
}
