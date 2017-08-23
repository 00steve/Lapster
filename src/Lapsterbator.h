#ifndef LAPSTERBATOR_H
#define LAPSTERBATOR_H

#ifndef SCREEN_SIZE_X
    #define SCREEN_SIZE_X 480
#endif // SCREEN_SIZE_X
#ifndef SCREEN_SIZE_Y
    #define SCREEN_SIZE_Y 320
#endif // SCREEN_SIZE_Y

#include <String.h>
#include <Arduino.h>
#include <SubSystem.h>

class Lapsterbator{
private:
    String lastError;

public:
    void PrintLastError();
    bool Setup();
    bool Update();

};



#endif
