#ifndef SUBSYSTEM_SETTINGS_H
#define SUBSYSTEM_SETTINGS_H

#include <Mode.h>
#include <Subsystem.h>
#include <Project3d.h>

class SubsystemSettings : public Mode{
private:
    Project3d projection;

public:
    SubsystemSettings();
    ~SubsystemSettings();

    void Update();
    void Draw();
    void Redraw();



};
#endif // SUBSYSTEM_SETTINGS_H
