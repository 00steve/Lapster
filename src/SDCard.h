#ifndef SD_CARD_H
#define SD_CARD_H

#include <SD.h>


#define sdCardSelectPin 5


class SDCard{
private:

    static File currentFile;
    static bool ready;

public:

    static bool Setup();

    static bool Ready();

    static bool Exists(String fileName);

    //static void DeleteDirectory(File dir, String tempPath);
    /*removes a directory and all of it's children
    files from the face of the earth. Only do this
    if you want to create enemies that will last until
    the rise of Zanthorth, with its fiery hell-bringing
    that will cleanse the earth of all the holy.*/
    static void Remove(String directoryName);

    static bool MakeDir(String directoryName);

    static String GetNextFileName(String pattern);

    static bool WriteOpen(String filename);

    static void WriteString(String data);

    static void WriteByte(byte data);
    static void WriteLong(long data);
    static void WriteFloat(float data);
    static void WriteDouble(double data);
    static void Write(byte* data,int byteSize);

    static bool WriteClose();

    static bool Writing();


};


#endif
