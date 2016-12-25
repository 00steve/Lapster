#ifndef SETTINGS_MENU_H
#define SETTINGS_MENU_H

#include <Mode.h>
#include <Button.h>

class SettingsMenu : public Mode{
private:

    Button backButton = Button(Int2(40,0),Int2(180,100),"Back");
    Button inputsButton = Button(Int2(190,0),Int2(330,100),"Inputs");
    Button gpsButton = Button(Int2(340,0),Int2(480,100),"GPS");
    Button compassButton = Button(Int2(40,110),Int2(180,210),"Compass");
    Button loggingButton = Button(Int2(190,110),Int2(330,210),"Logging");
    Button storageButton = Button(Int2(340,110),Int2(480,210),"Storage");
    Button accelerometerButton = Button(Int2(40,220),Int2(180,320),"Accelerometer");
    Button gyrometerButton = Button(Int2(190,220),Int2(330,320),"Gyrometer");



    /*

    gMeterButton = new Button(Int2(10,100),Int2(236,160),"G-Meter");
    //tracePathButton = new Button(int2(10,170),int2(236,230),"Trace Path",NULL);
    serialButton = new Button(Int2(10,170),Int2(236,230),"Serial Connection");
    dataLoggerButton = new Button(Int2(10,240),Int2(236,300),"Data Logger");
    expansionButton = new Button(Int2(246,100),Int2(470,160),"Analog Inputs");
    microSdButton = new Button(Int2(246,240),Int2(470, 300),"SD Card");
    */

    /*
    Button *gMeterButton = NULL;
    Button *tracePathButton = NULL;
    Button *dataLoggerButton = NULL;
    Button *expansionButton = NULL;
    Button *microSdButton = NULL;
    Button *serialButton = NULL;
    */

    void CustomInput();

public:

    SettingsMenu();
    ~SettingsMenu();

    void Update();
    void Draw();
    void Redraw();

};

#endif
