#ifndef GYROMETER_H
#define GYROMETER_H

#include <Wire.h>
#include <L3G4200D.h>
#include <Input.h>


#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

#define  NUM_GYRO_SAMPLES  50           // As recommended in STMicro doc
#define  GYRO_SIGMA_MULTIPLE  2.95        // As recommended (no actually 3 is recommended)

class Gyrometer : public Input {

private:

    static int address; //I2C address of the L3G4200D
    static Double3 rotation;
    static bool initialized;

    int gyroI2CAddr=105;
    short gyroRaw[3];                         // raw sensor data, each axis, pretty useless really but here it is.
    double gyroDPS[3];                      // gyro degrees per second, each axis
    float heading[3]={0.0f};                // heading[x], heading[y], heading [z]
    int gyroZeroRate[3];                    // Calibration data.  Needed because the sensor does center at zero, but rather always reports a small amount of rotation on each axis.
    int gyroThreshold[3];                   // Raw rate change data less than the statistically derived threshold is discarded.
    float dpsPerDigit=.00875f;              // for conversion to degrees per second




    // this simply returns the elapsed time since the last call.
    unsigned long getDeltaTMicros();
    void setGyroSensitivity250(void);
    void setGyroSensitivity500(void);
    void setGyroSensitivity2000(void);
    int gyroReadI2C (byte regAddr);
    void gyroWriteI2C( byte regAddr, byte val);


    void updateHeadings();
    void updateGyroValues();
    void calibrateGyro();

protected:
    virtual void SetTilt(Double3 tilt);


public:

    virtual void Setup();
    virtual String StatusString();
    virtual void Update();
    virtual String Label();

    Double3 Raw();
    Double3 DPS();

};







#endif
