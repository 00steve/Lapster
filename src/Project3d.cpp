#include <Project3d.h>

Project3d::Project3d(){
    maxDepth = 1;
    minDepth = -1;
    depthRatio = .5;
    topLeft = Int2(100,100);
    drawSize = Int2(200,200);
    color = 0xFFFF;
}

Project3d::Project3d(Int2 topLeft,Int2 drawSize){
    maxDepth = 1;
    minDepth = -1;
    depthRatio = .5;
    this->topLeft = topLeft;
    this->drawSize = drawSize;
    color = 0xFFFF;
}

Int2 Project3d::ProjectPoint(Double3 point){
    double mult = Map(point.Z,minDepth,maxDepth,depthRatio,1);
    double x = Map(mult*point.X,-1,1,0,drawSize.x)+topLeft.x;
    double y = Map(mult*point.Y,1,-1,0,drawSize.y)+topLeft.y;
    return Int2(x,y);
}

unsigned int Project3d::Color(unsigned int color){
    return this->color = color;
}
unsigned int Project3d::Color(){
    return color;
}

void Project3d::Clear(){
    tft.fillRect(topLeft.x,topLeft.y,drawSize.x,drawSize.y,0x0000);
}

void Project3d::DrawLine(Double3 pointA,Double3 pointB){
    Int2 a = ProjectPoint(pointA);
    Int2 b = ProjectPoint(pointB);
    //Serial.print(a.x);
    //Serial.print(",");
    //Serial.print(a.y);
    //Serial.print(" - ");
    //Serial.print(b.x);
    //Serial.print(",");
    //Serial.println(b.y);
    tft.drawLine(a.x,a.y,b.x,b.y,color);
}


void Project3d::Draw(){}
