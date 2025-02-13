#ifndef EXC1_FOOBAR_H
#define EXC1_FOOBAR_H

#include "BloomFilter.h"

#include <iostream>
#include <sstream>
#include <string>

class Foobar
{
private:
    // members
    BloomFilter bf;

public:
    // constructor
    Foobar();
    // getters
    // the [[nodiscard]] serves for catching logical errors. If we ask for the bloomfilter we must use it!
    [[nodiscard]] const BloomFilter &getBloomFilter() const;
    // other methods
    static BloomFilter searchBloomFilter();
    void run();
    static std::string printOut(bool isBlacklisted);
};

#endif // EXC1_FOOBAR_H