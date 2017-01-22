#ifndef GPS_SETTINGS_H
#define GPS_SETTINGS_H

#include <Mode.h>
#include <Timer.h>


class GPSSettings : public Mode {
private:

    Button *backButton = NULL;
    bool force;

    short oldSatellites;
    bool oldFix;
    int oldFixQuality;

    int oldDay, oldMonth, oldYear;
    int oldSecond, oldMinute, oldHour;

    float oldLat, oldLon, oldAlt;


    void Setup(){
        backButton = new Button(Int2(10,10),Int2(110,90),"Back");
        force = false;

        oldSatellites = -1;
        oldFix = false;
        oldFixQuality = -1;

        oldDay = -1;
        oldMonth = -1;
        oldYear = -1;

        oldSecond = -1;
        oldMinute = -1;
        oldHour = -1;

        oldLat = -1000;
        oldLon = -1000;
        oldAlt = -100000;

    }


public:

    GPSSettings(){
        Setup();
        Redraw();
    }


    void Update(){
        if(Button::CheckForScreenPress()){
            if(backButton->Pressing()){
                Set(MODE_SETTINGS);
            }
        }

        if (Subsystem::gps.sentenceAvailable()) Subsystem::gps.parseSentence();

        if (Subsystem::gps.newValuesSinceDataRead()) {
            Subsystem::gps.dataRead();
            //Serial.printf("Location: %f, %f altitude %f\n\r",
            //Subsystem::gps.latitude, Subsystem::gps.longitude, Subsystem::gps.altitude);

                Draw();

        }


    }

    void ForceDraw(){
        force = true;
        Draw();
    }

    void Draw(){
        if(Subsystem::gps.satellites != oldSatellites || force){
            oldSatellites = Subsystem::gps.satellites;
            tft.fillRect(220,100,26,14,0x0000);
            tft.setCursor(220,100);
            tft.print(oldSatellites);
        }
        if(Subsystem::gps.fix != oldFix || force){
            oldFix = Subsystem::gps.fix;
            tft.fillRect(220,120,60,14,0x0000);
            tft.setCursor(220,120);
            if(oldFix){
                tft.print("true");
            } else {
                tft.print("false");
            }
        }
        if(Subsystem::gps.fixquality != oldFixQuality || force){
            oldFixQuality = Subsystem::gps.fixquality;
            tft.fillRect(220,140,70,14,0x0000);
            tft.setCursor(220,140);
            switch(oldFixQuality){
            case 0: tft.print("None"); break;
            case 1: tft.print("GPS"); break;
            case 2: tft.print("DGPS"); break;
            }
        }

        if(Subsystem::gps.seconds != oldSecond || force){
            oldSecond = Subsystem::gps.seconds;
            tft.fillRect(320,190,50,14,0x0000);
            tft.setCursor(320,190);
            if(oldSecond < 10) tft.print("0");
            tft.print(oldSecond);

            if(Subsystem::gps.minute != oldMinute || force){
                oldMinute = Subsystem::gps.minute;
                tft.fillRect(270,190,26,14,0x0000);
                tft.setCursor(270,190);
                if(oldMinute < 10) tft.print("0");
                tft.print(oldMinute);

                if(Subsystem::gps.hour != oldHour || force){
                    oldHour = Subsystem::gps.hour;
                    tft.fillRect(220,190,26,14,0x0000);
                    tft.setCursor(220,190);
                    if(oldHour < 10) tft.print("0");
                    tft.print(oldHour);

                    if(Subsystem::gps.day != oldDay || force){
                        oldDay = Subsystem::gps.day;
                        tft.fillRect(270,170,26,14,0x0000);
                        tft.setCursor(270,170);
                        tft.print(oldDay);

                        if(Subsystem::gps.month != oldMonth || force){
                            oldMonth = Subsystem::gps.month;
                            tft.fillRect(220,170,26,14,0x0000);
                            tft.setCursor(220,170);
                            tft.print(oldMonth);

                            if(Subsystem::gps.year != oldYear || force){
                                oldYear = Subsystem::gps.year;
                                tft.fillRect(320,170,50,14,0x0000);
                                tft.setCursor(320,170);
                                tft.print(oldYear+2000);
                            }//end of year
                        }//end of month
                    }//end of days
                }//end of hours
            }//end of minutes
        }//end of seconds


        if(Subsystem::gps.latitude != oldLat || force){
            oldLat = Subsystem::gps.latitude;
            tft.fillRect(220,210,130,14,0x0000);
            tft.setCursor(220,210);
                tft.print(Subsystem::gps.latitude,6);
        }

        if(Subsystem::gps.longitude != oldLon || force){
            oldLon = Subsystem::gps.longitude;
            tft.fillRect(220,230,130,14,0x0000);
            tft.setCursor(220,230);
                tft.print(Subsystem::gps.longitude,6);
        }
        if(Subsystem::gps.altitude != oldAlt || force){
            oldAlt = Subsystem::gps.altitude;
            tft.fillRect(220,250,130,14,0x0000);
            tft.setCursor(220,250);
                tft.print(Subsystem::gps.altitude,6);
        }

        force = false;

    }

    void Redraw(){
        tft.fillScreen(0x0000);
        tft.setCursor(140,40);
        tft.setTextColor(0xFFFF);
        tft.setTextSize(3);
        tft.print("GPS Snoop");

        tft.setTextSize(2);

        tft.setCursor(10,100);
        tft.print("Satellite Locks : ");
        tft.setCursor(10,120);
        tft.print("Location Fixed  : ");
        tft.setCursor(10,140);
        tft.print("Fix Quality     : ");
        tft.drawLine(10,162,470,162,0xffff);
        tft.setCursor(10,170);
        tft.print("Date (UTC)      :   /   /");
        tft.setCursor(10,190);
        tft.print("Time (UTC)      :   :   :");
        tft.setCursor(10,210);
        tft.print("Latitude        :");
        tft.setCursor(10,230);
        tft.print("Longitude       :");
        tft.setCursor(10,250);
        tft.print("Altitude (feet) :");





        backButton->Draw();

        ForceDraw();
    }

};





#endif
