#ifndef IINPUTCHANNEL_H
#define IINPUTCHANNEL_H

#include <string>

class IInputChannel {
public:
    virtual ~IInputChannel() = default;
    // Attempts to read a line. Returns true if successful.
    virtual bool getLine(std::string &line) = 0;
};

#endif // IINPUTCHANNEL_H
