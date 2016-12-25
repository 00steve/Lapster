#ifndef DASHBOARD_H
#define DASHBOARD_H


#include <Mode.h>
#include <Button.h>
#include <Subsystem.h>
#include <DashboardLayout.h>
#include <Slider.h>

class Dashboard: public Mode{
private:

    Slider backButton = Slider(Int2(0,0),Int2(480,320),100);

    DashboardLayout *dashboardLayout = NULL;


    void Setup();

public:

    Dashboard();
    ~Dashboard();


    virtual void Update();
    virtual void Draw();
    virtual void Redraw();


};




#endif // DASHBOARD_H
