#include "Eprom.h"



    //this should only be called if the settings are being reset
    //or there are no settings yet saved to the Eprom
void Eprom::PopulateDefaults(){
    WriteShort(ACCELEROMETER_X_MIN_SHORT,395);
    WriteShort(ACCELEROMETER_X_MAX_SHORT,624);
    WriteShort(ACCELEROMETER_Y_MIN_SHORT,390);
    WriteShort(ACCELEROMETER_Y_MAX_SHORT,621);
    WriteShort(ACCELEROMETER_Z_MIN_SHORT,403);
    WriteShort(ACCELEROMETER_Z_MAX_SHORT,610);
    //define the scale of the g-meter.Since it is stored
    //as a char 0-255, each step represents 0.01 Gs, so we
    //can handle of scale of .01 - 2.56Gs. Default is 99
    //which translates to 1.00Gs
    WriteShort(ACCELEROMETER_SCALE,99);
    WriteShort(ACCELEROMETER_SMOOTHING,10);

    WriteShort(TOUCHSCREEN_X_MIN_SHORT,86);
    WriteShort(TOUCHSCREEN_X_MAX_SHORT,929);
    WriteShort(TOUCHSCREEN_Y_MIN_SHORT,129);
    WriteShort(TOUCHSCREEN_Y_MAX_SHORT,857);

    WriteChar(DATA_LOG_DEFAULT_SENSOR_CHAR,255);
    WriteShort(DATA_LOG_EXPANSION_SHORT,0);
    WriteShort(DATA_LOG_EXPANSION_SHORT+1,0);



}

void Eprom::Setup(){
    Serial.print("[Eprom]\n");
    //check if the first bit of the Eprom has the default value
    //of 255. If it does, set it to anything other than 255 and run
    //the populateDefaults function to set all of the initial settings.
    if(EEPROM.read(EEPROM_POPULATED_CHAR)!=0){
        Serial.print("- Write default settings values to Eprom\n");
        WriteChar(EEPROM_POPULATED_CHAR,0);
        PopulateDefaults();
    } else {
        Serial.print(" - Eprom has already been programmed\n");
        //use this to add or update the way shit is stored in the Eprom
        //populateDefaults();
    }
}

void Eprom::WriteChar(int address,char value){
    EEPROM.write(address,value);
}
void Eprom::WriteShort(int address,short value){
    EEPROM.write(address,value >> 4);
    EEPROM.write(address+1,value &0x0F);
}
void Eprom::WriteString(int address,String value){
    int len = value.length()+1;
    char cbuff[len];//Finds length of string to make a buffer
    value.toCharArray(cbuff,len);//Converts String into character array
        Serial.println(value);
    for(int i=0;i<len;i++){
        EEPROM.write(address++,cbuff[i]);
        Serial.println(cbuff[i],DEC);
    }
    Serial.println("----------------");
}

void Eprom::WriteString(int address,String value,unsigned int maxLength){
    unsigned int len;
    if(value.length() > maxLength){
        len = maxLength;
    } else {
        len = value.length();
    }
    char cbuff[len+1];//Finds length of string to make a buffer
    value.toCharArray(cbuff,len+1);//Converts String into character array

        Serial.println(value);
    Serial.println("keyboard return ");
    for(unsigned int i=0;i<value.length();i++){
        Serial.print(i);
        Serial.print(" : ");
        Serial.println(cbuff[i]);
    }
    Serial.println("-----------------");

    for(unsigned int i=0;i<len;i++){
        EEPROM.write(address++,cbuff[i]);
        Serial.print(i);
        Serial.print(" : ");
        Serial.println(cbuff[i]);
    }
    if(len < maxLength){
        EEPROM.write(address,cbuff[len]);
        Serial.print(len);
        Serial.println(" : 0");
    }
    Serial.println("----------------");
}


char Eprom::ReadChar(int address){
    return EEPROM.read(address);
}
short Eprom::ReadShort(int address){
    return (EEPROM.read(address) << 4) | (EEPROM.read(address+1) & 0xFF);
}


String Eprom::ReadString(int address,int len){
    String stemp="";
    char c;
    for(int i=0;i<len;i++)
    {
      c = EEPROM.read(address++);
      if(c == 0) break;
      stemp.concat(c);//combines characters into a String
    }
    return stemp;

}


bool Eprom::GetBit(unsigned char value, int position){ // position in range 0-7
    return (value >> position) & 0x1;
}
void Eprom::SetBit(unsigned char &container,int offset,bool value){
    container ^= (-value ^ container) & (1 << offset);
}

bool Eprom::GetBit(unsigned long container, int position){ // position in range 0-7
    return (container >> position) & 0x1;
}
void Eprom::SetBit(unsigned long int &container,int offset,bool value){
    container ^= (-value ^ container) & (1 << offset);
}

