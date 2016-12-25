#include "StorageMenu.h"



StorageMenu::StorageMenu():
        confirmClearLogs(false)
        {
    Redraw();
}

StorageMenu::~StorageMenu(){
}

void StorageMenu::Draw(){
}

void StorageMenu::Redraw(){
    tft.fillScreen(0x0000);


    DrawTitle("Storage Settings");

    Button::SetTftSettings();

    backButton.Draw();
    printFilesButton.Draw();
    clearLogsButton.Draw();
    reconnectButton.Draw();

    if(!SDCard::Ready()){
        tft.setCursor(190,10);
        tft.print("No SD card could be found.");
    }


}

void StorageMenu::Update(){
    if(confirmClearLogs){
        Serial.println("cleared logs, not really, but this is what would happen");
        Subsystem::sdCard.Remove("LOG/");
        confirmClearLogs = false;
    }

    if(Button::CheckForScreenPress()){
        if(backButton.Pressing()){
            Set(MODE_SETTINGS);
        }
        if(printFilesButton.Pressing()){
            if(!SDCard::Ready()){
                Serial.println("sd card could not be read.");
                return;
            }
            File root = SD.open("/");
            PrintDirectory(root, 0);
        }
        if(clearLogsButton.Pressing()){
            PushState(new Confirm(String("Are you sure you want to clear all logs. They will be gone. Forever. Press yes to forget the most important thing in your life."),&confirmClearLogs));
        }

        if(reconnectButton.Pressing()){
            SDCard::Setup();
        }

    }
}

void StorageMenu::PrintDirectory(File dir, int numTabs) {
    while (true) {
        File entry =  dir.openNextFile();
        if (! entry) {
            break;
        }
        for (int i = 0; i < numTabs; i++) {
            Serial.print('\t');
        }
        Serial.print(entry.name());
        if (entry.isDirectory()) {
            Serial.println("/");
            PrintDirectory(entry, numTabs + 1);
        } else {
            // files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
        }
        entry.close();
    }
}
