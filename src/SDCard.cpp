#include "SDCard.h"

File SDCard::currentFile;
bool SDCard::ready = false;


bool SDCard::Setup(){
    pinMode(sdCardSelectPin,OUTPUT);
    pinMode(10, OUTPUT);
    if (!SD.begin(sdCardSelectPin)) {
        Serial.println("[SD card initialization failed]");
        return ready = false;
    }
    Serial.println("[SD card initialization succeeded]");
    return ready = true;
}

bool SDCard::Ready(){ return ready; }

bool SDCard::Exists(String fileName){
    return SD.exists(fileName.c_str());
}

bool SDCard::MakeDir(String directoryName){
    if(SD.exists(directoryName.c_str())){
        return true;
    }
    return SD.mkdir(directoryName.c_str());
}

String SDCard::GetNextFileName(String pattern){
    int n = pattern.indexOf("::");
    String file;
    String ext;
    if(n > -1){
        file = pattern.substring(0,n);
        ext = pattern.substring(n+2);
    } else {
        file = "";
        ext = pattern;
    }
    n = 0;
    while(SD.exists((file + String(n) + ext).c_str())){
        ++n;
    }
    return file + String(n) + ext;

}

bool SDCard::WriteOpen(String filename){
    if(currentFile) return false;
    currentFile = SD.open(filename.c_str(),FILE_WRITE);
    return currentFile;
}

void SDCard::WriteString(String data){
    currentFile.write(data.c_str(),data.length());
}

void SDCard::WriteByte(byte data){
    currentFile.write(&data,1);
}

void SDCard::WriteLong(long data){
    char* b = reinterpret_cast<char*>(&data);
    currentFile.write(b,4);
}

void SDCard::WriteFloat(float data){
    char* b = reinterpret_cast<char*>(&data);
    currentFile.write(b,4);
}
void SDCard::WriteDouble(double data){
    char* b = reinterpret_cast<char*>(&data);
    currentFile.write(b,8);
}

void SDCard::Write(byte* data,int byteSize){
    currentFile.write(data,byteSize);
}

bool SDCard::Writing(){
    return currentFile;
}

bool SDCard::WriteClose(){
    if(!currentFile) return false;
    currentFile.close();
    return true;
}

void SDCard::Remove(String directoryName){
    SD.remove(directoryName.c_str());
}

