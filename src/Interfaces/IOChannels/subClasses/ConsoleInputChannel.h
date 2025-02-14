#ifndef CONSOLEINPUTCHANNEL_H
#define CONSOLEINPUTCHANNEL_H

#include "../IInputChannel.h"

#include <iostream>
#include <string>

class ConsoleInputChannel : public IInputChannel {
public:
    // Wrap an existing input stream (std::cin, a file stream, etc.)
    explicit ConsoleInputChannel(std::istream &in) : in(in) {}

    bool getLine(std::string &line) override {
        return static_cast<bool>(std::getline(in, line));
    }

private:
    std::istream &in;
};

#endif // CONSOLEINPUTCHANNEL_H
