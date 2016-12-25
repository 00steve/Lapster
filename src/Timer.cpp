#include <Timer.h>

elapsedMillis Timer::timer;
long Timer::lastTime;

void Timer::SetTilt(Double3 tilt){
}


void Timer::Setup(){
    lastTime = lastTick = timer;
    ticksPerSecond = 1;
    tickLength = 1;
    dropTicks = false;
}

Timer::Timer(){
    lastTick = lastTime;
    record = true;
}


String Timer::StatusString(){
    return "timer: elapsed time : " + String(lastTime) + "\n";
}

void Timer::Update(){
    lastTime = timer;
    newData = true;
}

String Timer::Label(){
    return "Timer";
}


long Timer::Milliseconds(){
    return lastTime;
}

double Timer::Seconds(){
    return (double)lastTime/(double)1000;
}


int Timer::TicksPerSecond(int ticksPerSecond){
    tickLength = (double) 1000/(double)ticksPerSecond;
    return this->ticksPerSecond = ticksPerSecond;
}

bool Timer::DropTicks(bool dropThem){
    return dropTicks = dropThem;
}

bool Timer::Tick(){
    if((double)lastTime - lastTick > tickLength){
        lastTick += tickLength;
        if(dropTicks){
            while(lastTick < (double)lastTime-tickLength){
                lastTick += tickLength;
            }
        }
        return true;
    }
    return false;
}
