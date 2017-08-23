#ifndef PROGRAMMABLE_H
#define PROGRAMMABLE_H

#include "Message.h"

class Programmable{
public:

    virtual SendMessage(Programmable *receiver,Message message);
    virtual ReceiveMessage(Message message);

};
#endif // PROGRAMMABLE_H
