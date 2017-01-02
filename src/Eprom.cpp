#include "Eprom.h"



    //this should only be called if the settings are being reset
    //or there are no settings yet saved to the Eprom
void Eprom::PopulateDefaults(){
    int cursor = ACCELEROMETER_X_MIN_SHORT;
    WriteShort(cursor,395);
    cursor = ACCELEROMETER_X_MAX_SHORT;
    WriteShort(cursor,624);
    cursor = ACCELEROMETER_Y_MIN_SHORT;
    WriteShort(cursor,390);
    cursor = ACCELEROMETER_Y_MAX_SHORT;
    WriteShort(cursor,621);
    cursor = ACCELEROMETER_Z_MIN_SHORT;
    WriteShort(cursor,403);
    cursor = ACCELEROMETER_Z_MAX_SHORT;
    WriteShort(cursor,610);
    //define the scale of the g-meter.Since it is stored
    //as a char 0-255, each step represents 0.01 Gs, so we
    //can handle of scale of .01 - 2.56Gs. Default is 99
    //which translates to 1.00Gs
    cursor = ACCELEROMETER_SCALE;
    WriteShort(cursor,99);
    cursor = ACCELEROMETER_SMOOTHING;
    WriteShort(cursor,10);

    cursor = TOUCHSCREEN_X_MIN_SHORT;
    WriteShort(cursor,86);
    cursor = TOUCHSCREEN_X_MAX_SHORT;
    WriteShort(cursor,929);
    cursor = TOUCHSCREEN_Y_MIN_SHORT;
    WriteShort(cursor,129);
    cursor = TOUCHSCREEN_Y_MAX_SHORT;
    WriteShort(cursor,857);

    cursor = DATA_LOG_DEFAULT_SENSOR_CHAR;
    WriteChar(cursor,255);
    cursor = DATA_LOG_EXPANSION_SHORT;
    WriteShort(cursor,0);
    WriteShort(cursor,0);


}

void Eprom::Setup(){
    Serial.print("[Eprom]\n");
    //check if the first bit of the Eprom has the default value
    //of 255. If it does, set it to anything other than 255 and run
    //the populateDefaults function to set all of the initial settings.
    int cursor = EEPROM_POPULATED_CHAR;
    if(EEPROM.read(cursor)!=0){
        Serial.print("- Write default settings values to Eprom\n");
        WriteChar(--cursor,0);
        PopulateDefaults();
    } else {
        Serial.print(" - Eprom has already been programmed\n");
        //use this to add or update the way shit is stored in the Eprom
        //populateDefaults();
    }
}

void Eprom::WriteChar(int &address,char value){
    EEPROM.write(address++,value);
}

void Eprom::WriteDouble(int &address,double value){
    char* b = reinterpret_cast<char*>(&value);
    EEPROM.write(address++,b[0]);
    EEPROM.write(address++,b[1]);
    EEPROM.write(address++,b[2]);
    EEPROM.write(address++,b[3]);
    EEPROM.write(address++,b[4]);
    EEPROM.write(address++,b[5]);
    EEPROM.write(address++,b[6]);
    EEPROM.write(address++,b[7]);
}

void Eprom::WriteFloat(int &address,float value){
    char* b = reinterpret_cast<char*>(&value);
    EEPROM.write(address++,b[0]);
    EEPROM.write(address++,b[1]);
    EEPROM.write(address++,b[2]);
    EEPROM.write(address++,b[3]);
}

void Eprom::WriteShort(int &address,short value){
    EEPROM.write(address++,value >> 4);
    EEPROM.write(address++,value &0x0F);
}
void Eprom::WriteString(int &address,String value){
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

void Eprom::WriteString(int &address,String value,unsigned int maxLength){
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
        EEPROM.write(address++,cbuff[len]);
        Serial.print(len);
        Serial.println(" : 0");
    }
    Serial.println("----------------");
}

void Eprom::WriteUShort(int &address,unsigned short value){
    char* b = reinterpret_cast<char*>(&value);
    EEPROM.write(address++,b[0]);
    EEPROM.write(address++,b[1]);
}








char Eprom::ReadChar(int &address){
    return EEPROM.read(address++);
}
double Eprom::ReadDouble(int &address){
    char b[4];
    b[0] = EEPROM.read(address++);
    b[1] = EEPROM.read(address++);
    b[2] = EEPROM.read(address++);
    b[3] = EEPROM.read(address++);
    b[4] = EEPROM.read(address++);
    b[5] = EEPROM.read(address++);
    b[6] = EEPROM.read(address++);
    b[7] = EEPROM.read(address++);
    double* d = reinterpret_cast<double*>(b);
    return d[0];
}
float Eprom::ReadFloat(int &address){
    char b[4];
    b[0] = EEPROM.read(address++);
    b[1] = EEPROM.read(address++);
    b[2] = EEPROM.read(address++);
    b[3] = EEPROM.read(address++);
    float* f = reinterpret_cast<float*>(b);
    return f[0];
}
short Eprom::ReadShort(int &address){
    address += 2;
    return (EEPROM.read(address-2) << 4) | (EEPROM.read(address-1) & 0xFF);
}


String Eprom::ReadString(int &address,int len){
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

unsigned short Eprom::ReadUShort(int &address){
    char b[4];
    b[0] = EEPROM.read(address++);
    b[1] = EEPROM.read(address++);
    unsigned short* s = reinterpret_cast<unsigned short*>(b);
    return s[0];
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

