#include "Gyrometer.h"


int Gyrometer::address = 909; //I2C address of the L3G4200D
Double3 Gyrometer::rotation = Double3(0,0,0);
bool Gyrometer::initialized = false;


// this simply returns the elapsed time since the last call.
unsigned long Gyrometer::getDeltaTMicros() {
    static unsigned long lastTime=0;
    unsigned long currentTime=micros();
    unsigned long deltaT=currentTime-lastTime;
    if (deltaT < 0.0) deltaT=currentTime+(4294967295-lastTime);
    lastTime=currentTime;
    return deltaT;
}



void Gyrometer::setGyroSensitivity250(void)
{
    dpsPerDigit=.00875f;
    gyroWriteI2C(CTRL_REG4, 0x80);        // Set scale (250 deg/sec)
}

void Gyrometer::setGyroSensitivity500(void)
{
    dpsPerDigit=.0175f;
    gyroWriteI2C(CTRL_REG4, 0x90);        // Set scale (500 deg/sec)
}

void Gyrometer::setGyroSensitivity2000(void)
{
    dpsPerDigit=.07f;
    gyroWriteI2C(CTRL_REG4,0xA0);
}

int Gyrometer::gyroReadI2C (byte regAddr) {
    Wire.beginTransmission(gyroI2CAddr);
    Wire.write(regAddr);
    Wire.endTransmission();
    Wire.requestFrom(gyroI2CAddr, 1);
    while(!Wire.available()) {};
    return (Wire.read());
}

void Gyrometer::gyroWriteI2C( byte regAddr, byte val){
    Wire.beginTransmission(gyroI2CAddr);
    Wire.write(regAddr);
    Wire.write(val);
    Wire.endTransmission();
}



    void Gyrometer::updateHeadings()
    {
        float deltaT=getDeltaTMicros();
        for (int j=0;j<3;j++){
            heading[j] -= (gyroDPS[j]*deltaT)/1000000.0f;
        }
    }
    void Gyrometer::updateGyroValues() {
        while (!(gyroReadI2C(0x27) & B00001000)){}      // Without this line you will get bad data occasionally
        //if (gyroReadI2C(0x27) & B01000000)
        //  Serial.println("Data missed!  Consider using an interrupt");
        int reg=0x28;
        for (int j=0;j<3;j++)
        {
            gyroRaw[j]=(gyroReadI2C(reg) | (gyroReadI2C(reg+1)<<8));
            reg+=2;
        }
        int deltaGyro[3];
        for (int j=0;j<3;j++)
        {
            deltaGyro[j]=gyroRaw[j]-gyroZeroRate[j];      // Use the calibration data to modify the sensor value.
            if (abs(deltaGyro[j]) < gyroThreshold[j]) deltaGyro[j]=0;
            gyroDPS[j]= dpsPerDigit * deltaGyro[j];      // Multiply the sensor value by the sensitivity factor to get degrees per second.
        }
    }




// Call this at start up.  It's critical that your device is completely stationary during calibration.
// The sensor needs recalibration after lots of movement, lots of idle time, temperature changes, etc, so try to work that in to your design.
void Gyrometer::calibrateGyro()
{
    long int gyroSums[3]={0};
    long int gyroSigma[3]={0};
    for (int i=0;i<NUM_GYRO_SAMPLES;i++)
    {
        updateGyroValues();
        for (int j=0;j<3;j++)
        {
            gyroSums[j]+=gyroRaw[j];
            gyroSigma[j]+=gyroRaw[j]*gyroRaw[j];
        }
    }
    for (int j=0;j<3;j++)
    {
        int averageRate=gyroSums[j]/NUM_GYRO_SAMPLES;
        // Per STM docs, we store the average of the samples for each axis and subtract them when we use the data.
        gyroZeroRate[j]=averageRate;
        // Per STM docs, we create a threshold for each axis based on the standard deviation of the samples times 3.
        gyroThreshold[j]=sqrt((double(gyroSigma[j]) / NUM_GYRO_SAMPLES) - (averageRate * averageRate)) * GYRO_SIGMA_MULTIPLE;
    }
    Serial.println("Threshold : ( " + String(gyroThreshold[0]) + "," + String(gyroThreshold[1]) + "," + String(gyroThreshold[2]) + ")");


    Serial.println("Done calibrating gyro");
}



void Gyrometer::Setup(){
    if(initialized) return;
    initialized = true;
    //delay(1000);
    gyroWriteI2C(CTRL_REG1, 0x1F);        // Turn on all axes, disable power down
    gyroWriteI2C(CTRL_REG3, 0x08);        // Enable control ready signal
    setGyroSensitivity500(); //go back to this if we need more processing power, right now 2k is pretty infuckingsane.
    //setGyroSensitivity2000();

    calibrateGyro();

    record = true;
}


void Gyrometer::Update(){
    updateGyroValues();
    updateHeadings();
    newData = true;
}

String Gyrometer::Label(){
    return "Gyrometer";
}



void Gyrometer::SetTilt(Double3 tilt){
}



String Gyrometer::StatusString(){
    return "DPS X: " + String(gyroDPS[0]) + "  Y: " + String(gyroDPS[1]) + "  Z: " + String(gyroDPS[2])+"\n";
}


Double3 Gyrometer::Raw(){ return Double3(gyroRaw[0],gyroRaw[1],gyroRaw[2]);}
Double3 Gyrometer::DPS(){ return Double3(gyroDPS[0],gyroDPS[1],gyroDPS[2]);}
