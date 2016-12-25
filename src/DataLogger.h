#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <Mode.h>
#include <Subsystem.h>


class DataLogger : public Mode{
private:

    String logFileName;

public:

    DataLogger();
    ~DataLogger();

    void Update();
    void Draw();
    void Redraw();

};



#endif
