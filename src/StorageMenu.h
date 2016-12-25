#ifndef STORAGE_MENU_H
#define STORAGE_MENU_H

#include <Mode.h>
#include <Icon.h>
#include <SDCard.h>
#include <Confirm.h>
#include <Subsystem.h>

class StorageMenu : public Mode{
private:
    Icon backButton = Icon(Int2(40,0),Int2(180,100),"Back",SYM_BACK);
    Button printFilesButton = Button(Int2(40,110),Int2(180,210),"Serial directory");
    Button clearLogsButton = Button(Int2(40,220),Int2(180,320),"Clear logs");
    Button reconnectButton = Button(Int2(190,110),Int2(330,210),"Reconnect");

    /*flag to store if clear logs has bee confirmed*/
    bool confirmClearLogs;

public:


    StorageMenu();
    ~StorageMenu();

    void Draw();
    void Redraw();
    void Update();

    void PrintDirectory(File dir, int numTabs);

};


#endif
