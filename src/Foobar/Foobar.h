#ifndef BLOOMFILTER_FOOBAR_H
#define BLOOMFILTER_FOOBAR_H

#include "../BloomFilter/BloomFilter.h"
#include "../Interfaces/Commands/ICommandable.h"
#include "../Interfaces/IOChannels/IInputChannel.h"
#include "../Interfaces/IOChannels/IOutputChannel.h"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <set>

class Foobar
{
private:
    // members
    IInputChannel &input;
    IOutputChannel &output;
    BloomFilter bf;

public:
    // constructor
    Foobar(IInputChannel &input, IOutputChannel &output);
    // getters
    // the [[nodiscard]] serves for catching logical errors. If we ask for the bloomfilter we must use it!
    [[nodiscard]] const BloomFilter &getBloomFilter() const;
    // other methods
    BloomFilter searchBloomFilter();
    std::unique_ptr<ICommandable> getCommand(std::istringstream &iss);
    void run();
};

#endif // BLOOMFILTER_FOOBAR_H