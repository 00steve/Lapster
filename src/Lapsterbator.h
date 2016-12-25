#ifndef LAPSTERBATOR_H
#define LAPSTERBATOR_H

#ifndef SCREEN_SIZE_X
    #define SCREEN_SIZE_X 480
#endif // SCREEN_SIZE_X
#ifndef SCREEN_SIZE_Y
    #define SCREEN_SIZE_Y 320
#endif // SCREEN_SIZE_Y



#include <Int2.h>
#include <Mode.h>
#include <Subsystem.h>
#include <Drawable.h>
#include "font_LiberationSans.h"

#include <MainMenu.h>
#include <Diagnostics.h>
#include <AlertScreen.h>
#include <SettingsMenu.h>
#include <InputsMenu.h>
#include <AnalogInputMenu.h>
#include <GPSSettings.h>
#include <CompassSettings.h>
#include <LoggingSettings.h>
#include <StorageMenu.h>
#include <DataLogger.h>
#include <AccelerometerSettings.h>
#include <GyrometerSettings.h>

#include <Dashboard.h>
#include <InputSelectMenu.h>


class Lapsterbator{
private:
    String lastError;
    Mode* current_process;
    /*build a stack of processes, we'll go 4 deep by default and
    see if for some reason the chip this shit is running on gets
    super pissed off and doesn't want it anymore.*/
    Mode** process_stack;
    int process_stack_height;

    bool showingAlert;

public:

    bool Setup();
    void Update();
    void PrintLastError();

};



#endif
