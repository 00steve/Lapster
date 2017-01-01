#include "Gauge.h"

//padding around the graph
int Gauge::graphPadding = 10;


Gauge::Gauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType) :
        topLeft(topLeft),
        bottomRight(bottomRight),
        center((topLeft + bottomRight)*.5),
        graphTopLeft(Int2(0,0)),
        graphBottomRight(Int2(0,0)){
    Subsystem::DataStreamRef(inputType,dataStreams,dataStreamCount);
}

Gauge::~Gauge(){
}

void Gauge::CalculateBounds(){
    center = (topLeft + bottomRight) * .5;
}

void Gauge::Draw(){}
void Gauge::Redraw(){}
void Gauge::References(double* references[],unsigned short referenceCount){}

double Gauge::MinValue(double newMinValue){
    return minValue = newMinValue;
}
double Gauge::MaxValue(double newMaxValue){
    return maxValue = newMaxValue;
}
double Gauge::MinValue(){
    return minValue;
}
double Gauge::MaxValue(){
    return maxValue;
}


Int2 Gauge::Size(Int2 newSize){
    bottomRight.x = topLeft.x + newSize.x;
    bottomRight.y = topLeft.y + newSize.y;
    CalculateBounds();
    return newSize;
}
Int2 Gauge::Position(Int2 newPosition){
    bottomRight += newPosition - topLeft;
    topLeft = newPosition;
    CalculateBounds();
    return newPosition;
}
Int2 Gauge::Size(){return bottomRight - topLeft; }
Int2 Gauge::Position(){ return topLeft; }
Int2 Gauge::TopLeft(){ return topLeft; }
Int2 Gauge::BottomRight(){ return bottomRight; }
Int2 Gauge::Center(){ return center; }

double Gauge::DataStreamValue(unsigned short index){
    if(index < dataStreamCount) return *dataStreams[index]->value;
    return 0;
}

double Gauge::DataStreamMinMap(unsigned short index){
    if(index < dataStreamCount) return *dataStreams[index]->mapMin;
    return 0;
}
double Gauge::DataStreamMaxMap(unsigned short index){
    if(index < dataStreamCount) return *dataStreams[index]->mapMax;
    return 0;
}
