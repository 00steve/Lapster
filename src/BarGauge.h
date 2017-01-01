#ifndef BAR_GAUGE_H
#define BAR_GAUGE_H

#include <Gauge.h>

class BarGauge : public Gauge{
private:
    int currentVal;
    int lastVal;
    int barWidth;

    int gaugeMin;
    int gaugeMax;
    int barValue;



public:
    BarGauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType);

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();
};



#endif // BAR_GAUGE_H
