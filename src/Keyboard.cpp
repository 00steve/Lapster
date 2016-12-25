#include "Keyboard.h"


void Keyboard::Setup(){

    timer.TicksPerSecond(2);

    valueX = 100;
    valueY = 40;

    backButton = new Button(Int2(10,10),Int2(90,90),"Back");
    delButton = new Button(Int2(410,10),Int2(470,90),"<--");

    int keyWidth = 43;
    int keyHeight = 50;
    int keySpace = 3;
    int x = 11;
    int y = 100;

    qButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"q"); x += keySpace;
    wButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"w"); x += keySpace;
    eButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"e"); x += keySpace;
    rButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"r"); x += keySpace;
    tButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"t"); x += keySpace;
    yButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"y"); x += keySpace;
    uButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"u"); x += keySpace;
    iButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"i"); x += keySpace;
    oButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"o"); x += keySpace;
    pButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"p"); x += keySpace;

    x = 34;
    y += keyHeight + keySpace;

    aButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"a"); x += keySpace;
    sButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"s"); x += keySpace;
    dButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"d"); x += keySpace;
    fButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"f"); x += keySpace;
    gButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"g"); x += keySpace;
    hButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"h"); x += keySpace;
    jButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"j"); x += keySpace;
    kButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"k"); x += keySpace;
    lButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"l"); x += keySpace;

    x = 57;
    y += keyHeight + keySpace;

    zButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"z"); x += keySpace;
    xButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"x"); x += keySpace;
    cButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"c"); x += keySpace;
    vButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"v"); x += keySpace;
    bButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"b"); x += keySpace;
    nButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"n"); x += keySpace;
    mButton = new Button(Int2(x,y),Int2(x+=keyWidth,y+keyHeight),"m"); x += keySpace;

    x = 80;
    y += keyHeight + keySpace;
    spaceButton = new Button(Int2(x,y),Int2(x+=keyWidth*4,y+keyHeight),""); x += keySpace;

}



Keyboard::Keyboard(String *value,short maxLength) :
        value(value),
        blinker(false),
        maxLength(maxLength)
        {
    Setup();
}

Keyboard::~Keyboard(){
    delete aButton;
    delete bButton;
    delete cButton;
    delete dButton;
    delete eButton;
    delete fButton;
    delete gButton;
    delete hButton;
    delete iButton;
    delete jButton;
    delete kButton;
    delete lButton;
    delete mButton;
    delete nButton;
    delete oButton;
    delete pButton;
    delete qButton;
    delete rButton;
    delete sButton;
    delete tButton;
    delete uButton;
    delete vButton;
    delete wButton;
    delete xButton;
    delete yButton;
    delete zButton;
    delete spaceButton;
    delete delButton;
    delete backButton;
}


void Keyboard::Update(){
    if(Button::CheckForScreenPress()){
        Serial.println("keyboard press");
        if(backButton->Pressing()){
            Button::WaitForDepress();
            Finished(true);
        }
        if(delButton->Pressing()){
            DrawDel();
            *value = value->substring(0,value->length()-1);
        }
        if(value->length() < maxLength){

            if(aButton->Pressing()) {*value += 'a';DrawDel();DrawChars(value->length()-1);}
            if(bButton->Pressing()) {*value += 'b';DrawDel();DrawChars(value->length()-1);}
            if(cButton->Pressing()) {*value += 'c';DrawDel();DrawChars(value->length()-1);}
            if(dButton->Pressing()) {*value += 'd';DrawDel();DrawChars(value->length()-1);}
            if(eButton->Pressing()) {*value += 'e';DrawDel();DrawChars(value->length()-1);}
            if(fButton->Pressing()) {*value += 'f';DrawDel();DrawChars(value->length()-1);}
            if(gButton->Pressing()) {*value += 'g';DrawDel();DrawChars(value->length()-1);}
            if(hButton->Pressing()) {*value += 'h';DrawDel();DrawChars(value->length()-1);}
            if(iButton->Pressing()) {*value += 'i';DrawDel();DrawChars(value->length()-1);}
            if(jButton->Pressing()) {*value += 'j';DrawDel();DrawChars(value->length()-1);}
            if(kButton->Pressing()) {*value += 'k';DrawDel();DrawChars(value->length()-1);}
            if(lButton->Pressing()) {*value += 'l';DrawDel();DrawChars(value->length()-1);}
            if(mButton->Pressing()) {*value += 'm';DrawDel();DrawChars(value->length()-1);}
            if(nButton->Pressing()) {*value += 'n';DrawDel();DrawChars(value->length()-1);}
            if(oButton->Pressing()) {*value += 'o';DrawDel();DrawChars(value->length()-1);}
            if(pButton->Pressing()) {*value += 'p';DrawDel();DrawChars(value->length()-1);}
            if(qButton->Pressing()) {*value += 'q';DrawDel();DrawChars(value->length()-1);}
            if(rButton->Pressing()) {*value += 'r';DrawDel();DrawChars(value->length()-1);}
            if(sButton->Pressing()) {*value += 's';DrawDel();DrawChars(value->length()-1);}
            if(tButton->Pressing()) {*value += 't';DrawDel();DrawChars(value->length()-1);}
            if(uButton->Pressing()) {*value += 'u';DrawDel();DrawChars(value->length()-1);}
            if(vButton->Pressing()) {*value += 'v';DrawDel();DrawChars(value->length()-1);}
            if(wButton->Pressing()) {*value += 'w';DrawDel();DrawChars(value->length()-1);}
            if(xButton->Pressing()) {*value += 'x';DrawDel();DrawChars(value->length()-1);}
            if(yButton->Pressing()) {*value += 'y';DrawDel();DrawChars(value->length()-1);}
            if(zButton->Pressing()) {*value += 'z';DrawDel();DrawChars(value->length()-1);}
            if(spaceButton->Pressing()) {*value += ' ';DrawDel();DrawChars(value->length()-1);}
            Serial.println(*value);
        }
    }
    Draw();
}


void Keyboard::Draw(){
    if(timer.Tick()){
        blinker = !blinker;
        tft.setCursor(valueX+value->length()*25,valueY);
        tft.setTextSize(4);
        if(blinker){
            tft.setTextColor(0xFFFF);
        } else {
            tft.setTextColor(0x0000);
        }
        tft.print("_");
        tft.setTextSize(2);
    }
}

void Keyboard::DrawDel(){
    tft.fillRect(valueX+value->length()*25,valueY,25,35,0x0000);
}

void Keyboard::DrawChars(unsigned int startingIndex){
    tft.setTextColor(0xFFFF);
    tft.setTextSize(4);
    while(startingIndex < value->length()){
        tft.setCursor(valueX + startingIndex*25,valueY);
        tft.print((*value)[startingIndex]);
        ++startingIndex;
    }
}


void Keyboard::Redraw(){
    tft.fillScreen(0x0000);

    backButton->Draw();
    delButton->Draw();

    DrawChars(0);


    tft.setTextSize(2);
    qButton->Draw(); wButton->Draw(); eButton->Draw(); rButton->Draw(); tButton->Draw(); yButton->Draw(); uButton->Draw(); iButton->Draw(); oButton->Draw(); pButton->Draw();
    aButton->Draw(); sButton->Draw(); dButton->Draw(); fButton->Draw(); gButton->Draw(); hButton->Draw(); jButton->Draw(); kButton->Draw(); lButton->Draw();
    zButton->Draw(); xButton->Draw(); cButton->Draw(); vButton->Draw(); bButton->Draw(); nButton->Draw(); mButton->Draw();

    spaceButton->Draw();



}

