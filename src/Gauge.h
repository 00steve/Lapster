#ifndef GAUGE_H
#define GAUGE_H

#include <Drawable.h>
#include <Subsystem.h>
#include <DataStream.h>

class Gauge : public Drawable{
private:
    double minValue;
    double maxValue;
    Int2 topLeft;
    Int2 bottomRight;
    Int2 center;

    Int2 graphTopLeft;
    Int2 graphBottomRight;

    DataStream** dataStreams;
    unsigned short dataStreamCount;

    void CalculateBounds();

protected:
    static int graphPadding;


public:
    Gauge(Int2 topLeft,Int2 bottomRight,unsigned short inputType);
    virtual ~Gauge();

    virtual void Draw();
    virtual void Redraw();
    virtual void References(double* references[],unsigned short referenceCount);

    double MinValue(double newMinValue);
    double MaxValue(double newMaxValue);
    double MinValue();
    double MaxValue();

    Int2 Size(Int2 newSize);
    Int2 Position(Int2 newPosition);
    Int2 Size();
    Int2 Position();
    Int2 TopLeft();
    Int2 BottomRight();
    Int2 Center();

    double DataStreamValue(unsigned short index);
    double DataStreamMinMap(unsigned short index);
    double DataStreamMaxMap(unsigned short index);
};
#endif // GAUGE_H
