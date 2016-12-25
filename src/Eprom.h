#ifndef EEPROM_STORAGE_H
#define EEPROM_STORAGE_H
#include <EEPROM.h>
#include <Wire.h>
#include <WString.h>

/*manages reading and writing to and from the eeprom. It reads up the the specified char
from the eeprom into memory. It also can store any values back into memory, values should
only be stored back into memory if they have changed. The eeprom memory has a specified
life of 100,000 write/erase cycles.*/

#define EEPROM_POPULATED_CHAR 0
#define ACCELEROMETER_X_MIN_SHORT 2
#define ACCELEROMETER_X_MAX_SHORT 4
#define ACCELEROMETER_Y_MIN_SHORT 6
#define ACCELEROMETER_Y_MAX_SHORT 8
#define ACCELEROMETER_Z_MIN_SHORT 10
#define ACCELEROMETER_Z_MAX_SHORT 12
#define ACCELEROMETER_SCALE 14
#define ACCELEROMETER_SMOOTHING 15

#define TOUCHSCREEN_X_MIN_SHORT 16
#define TOUCHSCREEN_X_MAX_SHORT 18
#define TOUCHSCREEN_Y_MIN_SHORT 20
#define TOUCHSCREEN_Y_MAX_SHORT 22

#define DATA_LOG_DEFAULT_SENSOR_CHAR 24
#define DATA_LOG_EXPANSION_SHORT 25


/*amount of data to store about each input type, like the name,
warning min, max, warning enabled, data type, input enabled, unit
label,
enabled     : char  : if the data source is being used
v_min       : short : minimum voltage that source will provide
                        Stored as 65535, each increment represents .0001 volts
                        as the min, a range of 0.0000 - 6.5535 volts at a scale of 4.
v_max       : short : maximum voltage that source will provide
                        Stored as 65535, each increment represents .0001 volts
                        as the min, a range of 0.0000 - 6.5535 volts at a scale of 4.
m_max       : float : what number of units the v_min maps to logged and displayed
                        Stored as a float so pretty much any value can be used.
m_min       : float : what number of units the v_max maps to when logged and displayed
                        Stored as a float so pretty much any value can be used.
w_min       : char  : minimum number of units allowed before user is warned (to turn off warning, set to min)
                        (w_min is stored as a scale from 0..1 of v_min and v_max, displayed to user as the unit equivalent,
                        thus will change if the v_min/max or m_min/max changes).
                        Stored as char, which is 0-255, only using 0-250 for nice round numbers when converting to a
                        percentage
w_max       : char  : maximum number of units allowed before user is warned (to turn off warning, set to max)
                        (w_max is stored as a scale from 0..1 of v_min and v_max, displayed to user as the unit equivalent,
                        thus will change if the v_min/max or m_min/max changes)
                        Stored as char, which is 0-255, only using 0-250 for nice round numbers when converting to a
                        percentage

*/



#define DATA_LOG_EXPANSION1_MEM_BLOCK 1023
#define DATA_LOG_EXPANSION2_MEM_BLOCK 1087
#define DATA_LOG_EXPANSION3_MEM_BLOCK 1151
//next is 201

class Eprom {
private:


    /*this should only be called if the settings are being reset
    or there are no settings yet saved to the eeprom*/
    static void PopulateDefaults();

public:

    static void Setup();

    static void WriteChar(int address,char value);
    static void WriteShort(int address,short value);
    static void WriteString(int address,String value);

    static void WriteString(int address,String value,unsigned int maxLength);


    static char ReadChar(int address);
    static short ReadShort(int address);

    static String ReadString(int address,int len);


    static bool GetBit(unsigned char value, int position);
    static void SetBit(unsigned char &container,int offset,bool value);

    static bool GetBit(unsigned long container, int position);
    static void SetBit(unsigned long int &container,int offset,bool value);


};


#endif
