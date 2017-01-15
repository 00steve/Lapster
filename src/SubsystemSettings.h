#ifndef SUBSYSTEM_SETTINGS_H
#define SUBSYSTEM_SETTINGS_H

#include <Mode.h>
#include <Icon.h>
#include <Subsystem.h>
#include <Project3d.h>
#include <Quaternion.h>

class SubsystemSettings : public Mode{
private:
    Project3d projection;

    Quaternion t;

    void Setup();

public:
    SubsystemSettings();
    ~SubsystemSettings();

    virtual void Update();
    virtual void Draw();
    virtual void Redraw();



};
#endif // SUBSYSTEM_SETTINGS_H
