#ifndef DASHBOARD_WIDGET_H
#define DASHBOARD_WIDGET_H

#include <Int2.h>
#include <Button.h>
#include <Gauge.h>
#include <EmptyGauge.h>
#include <BarGauge.h>

#define GAUGE_TYPE_EMPTY    10
#define GAUGE_TYPE_BAR      20

class DashboardWidget : public Button {
private:
    Gauge* gauge;
    unsigned short inputType;

    double* drawMinValue;
    double* drawMaxValue;
    double* warnMinValue;
    double* warnMaxValue;
public:

    DashboardWidget(Int2 topLeft,Int2 bottomRight,unsigned short gaugeType,unsigned short inputType);

    unsigned short GaugeType(unsigned short newGaugeType);
    unsigned short InputType(unsigned short newInputType);

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();

    Int2 Size(Int2 newSize);
    Int2 Position(Int2 newPosition);
    Int2 Size();
    Int2 Position();

};


#endif
