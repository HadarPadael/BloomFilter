#ifndef CONSOLEOUTPUTCHANNEL_H
#define CONSOLEOUTPUTCHANNEL_H

#include "../IOutputChannel.h"

#include <iostream>

class ConsoleOutputChannel : public IOutputChannel {
public:
    void write(const std::string &message) override
    {
        std::cout << message;
    }
};

#endif // CONSOLEOUTPUTCHANNEL_H
