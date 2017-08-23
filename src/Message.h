#ifndef MESSAGE_H
#define MESSAGE_H

class Programmable;

class Message{
public:
    void* data;
    unsigned int dataCode;
    Programmable *sender;
};


#endif // MESSAGE_H
