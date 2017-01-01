#ifndef EMPTY_GAUGE_H
#define EMPTY_GAUGE_H

#include <Gauge.h>

class EmptyGauge : public Gauge{
public:

    EmptyGauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType);


    virtual void Draw();
    virtual void Redraw();




};

#endif // EMPTY_GAUGE_H
