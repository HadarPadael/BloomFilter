#ifndef IOUTPUTCHANNEL_H
#define IOUTPUTCHANNEL_H

#include <string>

class IOutputChannel {
public:
    virtual ~IOutputChannel() = default;
    virtual void write(const std::string &message) = 0;
};

#endif // IOUTPUTCHANNEL_H
