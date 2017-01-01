#ifndef DATA_STREAM_H
#define DATA_STREAM_H

#include <Input.h>

struct DataStream{
public:

    double* value;
    double* mapMin;
    double* mapMax;
    double* warnMin;
    double* warnMax;

    Input* input;

};

#endif // DATA_STREAM_H
