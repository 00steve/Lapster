#ifndef MODE_H
#define MODE_H


/*define mode IDs that can be used to switch
mode by the main loop.*/
#define MODE_MAIN_MENU 0
#define MODE_G_METER 1
#define MODE_TRACE_PATH 2
#define MODE_ZERO_SIXTY 3
#define MODE_SETTINGS 4
#define MODE_ABOUT 5
#define MODE_G_METER_SETTINGS 6
#define MODE_DATA_LOGGER 50
#define MODE_DATA_LOGGER_SETTINGS 51
#define MODE_EXPANSION_SETTINGS 60
#define MODE_GPS_SETTINGS 70
#define MODE_MICROSD_SETTINGS 80
#define MODE_SERIAL_SETTINGS 90
#define MODE_DIAGNOSTICS 100
#define MODE_ALERT 110
#define MODE_INPUTS_MENU 120
#define MODE_ANALOG_INPUT_MENU_1 150
#define MODE_ANALOG_INPUT_MENU_2 151
#define MODE_COMPASS_SETTINGS 200
#define MODE_LOGGING_SETTINGS 210
#define MODE_STORAGE_SETTINGS 220
#define MODE_ACCELEROMETER_SETTINGS 230
#define MODE_GYROMETER_SETTINGS 240
#define MODE_DASHBOARD 300
#define MODE_WIDGET_SETTINGS 310
#define MODE_INPUT_SELECT_MENU 400
#define MODE_SUBSYSTEM_SETTINGS 410

#include <Button.h>
#include <Drawable.h>
#include <Swipe.h>
class Mode : public Drawable{
private:

    bool finished;
    int nextMode;

    Mode *nextState;

protected:

    void Set(int newMode);
    void DrawTitle(String title);

public:

    Mode() :
        finished(false),
        nextState(NULL)
    {
    }

    virtual ~Mode(){
        if(nextState) delete nextState;
    }

    virtual void Redraw()=0;
    virtual void Update()=0;


    bool Finished(bool finished);
    bool Finished();
    void PushState(Mode *nextState);
    bool HasPushState();
    Mode *PushState();
    bool PopState();
    int NextMode();

};

#endif

