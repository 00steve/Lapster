#ifndef LOGGING_SETTINGS_H
#define LOGGING_SETTINGS_H

#include <Mode.h>
#include <Button.h>


class LoggingSettings : public Mode{
private:

    Button backButton = Button(Int2(50,0),Int2(160,80),"Back");

public:

    LoggingSettings();
    ~LoggingSettings();

    virtual void Draw();
    virtual void Redraw();
    virtual void Update();



};



#endif
