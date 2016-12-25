#ifndef TIMER_H
#define TIMER_H

#include <WString.h>
#include <Input.h>
#include <elapsedMillis.h>


class Timer : public Input{
private:
    static elapsedMillis timer;
    static long lastTime;
    int ticksPerSecond;
    double lastTick;
    double tickLength;
    bool dropTicks;
protected:
    virtual void SetTilt(Double3 tilt);

public:
    Timer();
    virtual void Setup();
    virtual void Update();
    virtual String Label();
    virtual String StatusString();
    long Milliseconds();
    double Seconds();

    /*if the timer runs slow, should it drop any extra ticks
    that were missed?*/
    bool DropTicks(bool dropThem);

    /*set the number of times the tick flag is set every second.
    If a loop calls the Tick() function, it will call it every
    however many milliseconds one tick should take, based on what
    is passed into this.*/
    int TicksPerSecond(int ticksPerSecond);

    bool Tick();

};


#endif
