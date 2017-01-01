#ifndef INPUT_H
#define INPUT_H

#include <WString.h>
#include <Double3.h>
#include <AlertInfo.h>
#include <WProgram.h>


#define ANALOG_INPUT_BITS 12


class Input{
private:

    static bool newAlert;
    static AlertInfo* alerts[24];
    static short alertCount;

    static short maxAnalogVoltageInt;

protected:


    bool enabled;
    bool record;
    /*store the offset of where the input stores its setting information
    in the eeprom.*/
    int eepromOffset;

    bool newData;


    virtual void SetTilt(Double3 tilt);

public:

    Input() : newData(false){
    };

    /*purely abstract functions that must be implemented by any input types
    that want to be treated as an input.*/
    virtual void Setup() = 0;
    virtual void Update() = 0;
    virtual String Label() = 0;
    virtual String Units();
    virtual String* UnitsRef();

    virtual String StatusString();

    virtual bool StoreSettingDefaults(int startEepromOffset);
    virtual bool StoreSettings(int startingEepromOffset);
    virtual bool StoreSettings();
    virtual bool LoadSettings(int startingEepromOffset);
    static bool Alert(AlertInfo* info);
    static bool NewAlert();
    static bool RemoveAlert(AlertInfo* info);
    static int AlertCount();

    static short MaxAnalogVoltageInt();
    static AlertInfo** Alerts();

    float MinimumVoltage();
    float MaximumVoltage();
    bool Enabled();
    void Enable();
    void Disable();
    int EepromOffset();

    bool NewData();

    bool Record();


};



#endif
