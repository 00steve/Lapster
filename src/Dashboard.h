#ifndef DASHBOARD_H
#define DASHBOARD_H


#include <Mode.h>
#include <Button.h>
#include <Subsystem.h>
#include <DashboardLayout.h>
#include <Swipe.h>

class Dashboard: public Mode{
private:

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
