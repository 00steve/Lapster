#include "AnalogInputMenu.h"

void AnalogInputMenu::Setup(){
    iRef = Subsystem::AnalogInputs[inputId];
    changed = false;
    units = String("psi");
    backButton = new Button(Int2(50,0),Int2(160,80),"Back");
    enabledCheck = new Checkbox(Int2(120,90),Int2(180,130),"",iRef->Enabled());
    nameButton = new Button(Int2(120,140),Int2(220,180),*iRef->LabelRef());
    unitsButton = new Button(Int2(120,190),Int2(220,230),units);

    vInMinSpinner = new NumberSpinner(Int2(300,90),Int2(380,130),iRef->MinimumVoltageRef(),0,5);
    vInMaxSpinner = new NumberSpinner(Int2(390,90),Int2(480,130),iRef->MaximumVoltageRef(),0,5);
    mapMinSpinner = new NumberSpinner(Int2(300,140),Int2(380,180),iRef->MinimumMapRef(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max());
    mapMaxSpinner = new NumberSpinner(Int2(390,140),Int2(480,180),iRef->MaximumMapRef(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max());
    wrnMinSpinner = new NumberSpinner(Int2(300,190),Int2(380,230),iRef->MinimumWarningRef(),0,250);
    wrnMaxSpinner = new NumberSpinner(Int2(390,190),Int2(480,230),iRef->MaximumWarningRef(),0,250);

    Serial.println("setup analog input menu");

    timer.TicksPerSecond(5);
}

AnalogInputMenu::AnalogInputMenu(int inputId) :
            inputId(inputId-MODE_ANALOG_INPUT_MENU_1)
        {
    Setup();
    Redraw();
}

AnalogInputMenu::~AnalogInputMenu(){
    delete backButton;
    delete enabledCheck;
    delete nameButton;
    delete unitsButton;
    delete vInMinSpinner;
    delete vInMaxSpinner;
    delete mapMinSpinner;
    delete mapMaxSpinner;
    delete wrnMinSpinner;
    delete wrnMaxSpinner;
}

void AnalogInputMenu::Draw(){
    tft.setFont(LiberationSans_24);
    tft.setTextColor(0xFFFF);
    newVoltage = iRef->Voltage();
    if((int)(100*oldVoltage) != (int)(100*newVoltage)){
        oldVoltage = newVoltage;
        tft.setCursor(240,10);
        tft.fillRect(240,10,290,40,0x0000);
        tft.print(oldVoltage);

    }
}

void AnalogInputMenu::Redraw(){
    tft.fillScreen(0x0000);
    DrawTitle("Analog Input " + String(inputId+1));

    Button::SetTftSettings();

    backButton->Draw();
    enabledCheck->Draw();
    nameButton->setText(*iRef->LabelRef());
    nameButton->Draw();
    unitsButton->setText(units);
    unitsButton->Draw();

    vInMinSpinner->Draw();
    vInMaxSpinner->Draw();
    mapMinSpinner->Draw();
    mapMaxSpinner->Draw();
    wrnMinSpinner->Draw();
    wrnMaxSpinner->Draw();


    tft.setCursor(50,103);
    tft.print("Enabled:");

    tft.setCursor(50,153);
    tft.print("Label:");

    tft.setCursor(50,203);
    tft.print("Units:");

    tft.setCursor(310,60);
    tft.print("Low:");

    tft.setCursor(400,60);
    tft.print("High:");

    tft.setCursor(230,103);
    tft.print("Voltage:");
    tft.setCursor(230,153);
    tft.print("Map:");
    tft.setCursor(230,203);
    tft.print("Warn:");

    tft.setCursor(170,10);
    tft.print("Voltage:");



    //tft.drawFastHLine(10,115,470,0xffff);


    //analogInput1Button->Draw();
}

void AnalogInputMenu::Update(){
    if(Button::CheckForScreenPress()){
        if(backButton->Pressing()){
            if(changed){
                iRef->StoreSettings();
            }
            Set(MODE_INPUTS_MENU);
            return;
        }
        if(enabledCheck->Pressing()){
           //do nothing
           Serial.println(enabledCheck->GetValue());
            enabledCheck->GetValue() ? iRef->Enable() : iRef->Disable();
            changed = true;
        }
        if(nameButton->Pressing()){
            PushState(new Keyboard(iRef->LabelRef(),16));
            changed = true;
        }
        if(unitsButton->Pressing()){
            PushState(new Keyboard(&units,6));
            changed = true;
        }
        vInMinSpinner->Pressing();
        vInMaxSpinner->Pressing();
        mapMinSpinner->Pressing();
        mapMaxSpinner->Pressing();
        wrnMinSpinner->Pressing();
        wrnMaxSpinner->Pressing();
    }

    if(Button::CheckForScreenDrag()){
        vInMinSpinner->Dragging();
        vInMaxSpinner->Dragging();
        mapMinSpinner->Dragging();
        mapMaxSpinner->Dragging();
        wrnMinSpinner->Dragging();
        wrnMaxSpinner->Dragging();
    }

    if(timer.Tick()) Draw();
}
