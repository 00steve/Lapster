#ifndef ANALOG_INPUT_H
#define ANALOG_INPUT_H

#include <WString.h>
#include <Input.h>
#include <Wire.h>
#include <AlertInfo.h>
#include <Eprom.h>
#include <limits>
#include <MathUtils.h>

class AnalogInput : public Input{
private:

    int pin;
    double voltage;
    double value;

    AlertInfo alertInfo;
    bool currentAlert;

    String label;

protected:


    //String labelstuff;

    double voltMin;
    double voltMax;
    double mapMin;
    double mapMax;
    double warnMin;
    double warnMax;

    virtual void SetTilt(Double3 tilt);

public:

    AnalogInput(int pin,int eepromOffset);

    virtual void Setup();
    virtual void Update();
    virtual String Label();

    virtual String StatusString();
    virtual bool StoreSettings();
    virtual bool StoreSettingDefaults(int startingEepromOffset);
    virtual bool LoadSettings(int startingEepromOffset);

    double Value();

    double Voltage();
    double MinimumVoltage();
    double MaximumVoltage();
    double MinimumMap();
    double MaximumMap();
    double MinimumWarning();
    double MaximumWarning();

    double* ValueRef();
    double* VoltageRef();
    double* MinimumVoltageRef();
    double* MaximumVoltageRef();
    double* MinimumMapRef();
    double* MaximumMapRef();
    double* MinimumWarningRef();
    double* MaximumWarningRef();
    String* LabelRef();

    static void RestoreInputSettings(int startingEepromOffset);
};



#endif
