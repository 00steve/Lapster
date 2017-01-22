#ifndef SUBSYSTEM_SETTINGS_H
#define SUBSYSTEM_SETTINGS_H

#include <Mode.h>
#include <Icon.h>
#include <Subsystem.h>
#include <Project3d.h>
#include <Quaternion.h>
#include <Cube.h>

class SubsystemSettings : public Mode, Subsystem{
private:
    Project3d projection;
    Project3d projection2;
    Project3d projection3;
    Project3d projection4;

    Quaternion t;
    Cube c;

    void Setup();

public:
    SubsystemSettings();
    ~SubsystemSettings();

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();



};
#endif // SUBSYSTEM_SETTINGS_H
