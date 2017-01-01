#include "Lapsterbator.h"


bool Lapsterbator::Setup(){
    /*don't get rid of this delay. It is required by the teensy 3.1s
    hardware. The IC2 channel isn't ready when the teensy starts up,
    so the program starts running and can't detect it so it shows a
    white screen instead of everything working correctly.*/

    lastError = "No errors so far.";
    Subsystem::Setup();

    Drawable::HarwareReference(Subsystem::screen.HardwareReference());
    Button::SetupButton();



    Subsystem::timer.Update();
    Subsystem::touch.Update();
    double timeStart = Subsystem::timer.Seconds();
    Serial.println("[Startup] completed in " + String(timeStart) + "s.");
    /*allow user to short cut startup and get to reset menu by pressing the screen for 5
    seconds after startup.*/
    int diagTime = 2;
    if(Subsystem::touch.Pressing()){
        Subsystem::screen.FillRect(0,0,480,60,WARNING_BACKGROUND);
        Subsystem::screen.Print(LiberationSans_16,ILI9341_WHITE,Int2(10,10),"Continue pressing screen for 2 seconds to enter ");
        Subsystem::screen.Print(LiberationSans_16,ILI9341_WHITE,Int2(10,30),"system diagnostics menu.");

        while(Subsystem::touch.Pressing() && Subsystem::timer.Seconds()-timeStart<diagTime){
            Subsystem::timer.Update();
            Subsystem::touch.Update();
        }
        if(Subsystem::touch.Pressing() && Subsystem::timer.Seconds()-timeStart>=diagTime){
            current_process = new Diagnostics();
        }

    }

    unsigned short x = 62000;
    char* b = reinterpret_cast<char*>(&x);
    unsigned short* s = reinterpret_cast<unsigned short*>(b);
    Serial.println(s[0]);



    if(!current_process){
        current_process = new MainMenu();
    }

    process_stack = new Mode*[5];
    showingAlert = false;
    return true;
}
void Lapsterbator::Update(){
    Subsystem::Update();

    /*check for any new alerts, that are not already being shown.*/
    if(!showingAlert && Input::NewAlert()){
        showingAlert = true;
        process_stack[process_stack_height++] = current_process;
        current_process = new AlertScreen();
    }

    current_process->Update();

    if(current_process->HasPushState()){
        process_stack[process_stack_height++] = current_process;
        current_process = current_process->PushState();
        current_process->Redraw();
    }
    if(process_stack_height > 0 && current_process->PopState()){
        showingAlert = false;
        delete current_process;
        current_process = process_stack[--process_stack_height];
        current_process->Redraw();
    }

    if(current_process->Finished()){
        delete current_process;
        //Serial.println("finished, switch state");
        switch(current_process->NextMode()){
            case MODE_MAIN_MENU:
                current_process = new MainMenu();
                break;
            /*
            case MODE_G_METER:
                current_process = new GMeter();
                break;
            case MODE_TRACE_PATH:
                current_process = new TracePath();
                break;
            */
            case MODE_SETTINGS:
                current_process = new SettingsMenu();
                break;
            case MODE_INPUTS_MENU:
                current_process = new InputsMenu();
                break;
            case MODE_ANALOG_INPUT_MENU_1:
            case MODE_ANALOG_INPUT_MENU_2:
                current_process = new AnalogInputMenu(current_process->NextMode());
                break;
            case MODE_GPS_SETTINGS:
                current_process = new GPSSettings();
                break;
            case MODE_COMPASS_SETTINGS:
                current_process = new CompassSettings();
                break;
            case MODE_LOGGING_SETTINGS:
                current_process = new LoggingSettings();
                break;
            case MODE_STORAGE_SETTINGS:
                current_process = new StorageMenu();
                break;
            case MODE_DATA_LOGGER:
                current_process = new DataLogger();
                break;
            case MODE_ACCELEROMETER_SETTINGS:
                current_process = new AccelerometerSettings();
                break;
            case MODE_GYROMETER_SETTINGS:
                current_process = new GyrometerSettings();
                break;

            case MODE_DASHBOARD:
                current_process = new Dashboard();
                break;

            /*case MODE_INPUTS:
                current_process = new InputsMenu();
                break;

            case MODE_G_METER_SETTINGS:
                current_process = new GMeterSettings();
                break;
            case MODE_DATA_LOGGER_SETTINGS:
                current_process = new DataLoggerSettings();
                break;
            case MODE_EXPANSION_SETTINGS:
                current_process = new ExpansionSettings();
                break;
            case MODE_MICROSD_SETTINGS:
                current_process = new sdCardSettings();
                break;
            case MODE_SERIAL_SETTINGS:
                current_process = new SerialSettings();
                break;*/
            default:

                Serial.println("No valid mode set, add the mode to the switch, ya bitch!");
        }
    }

}
void Lapsterbator::PrintLastError(){

    Serial.println("error: " + lastError);
}
