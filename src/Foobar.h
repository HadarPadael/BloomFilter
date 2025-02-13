#ifndef BLOOMFILTER_FOOBAR_H
#define BLOOMFILTER_FOOBAR_H

#include "BloomFilter.h"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <set>
#include "ICommandable.h"

class Foobar
{
private:
    // members
    BloomFilter bf;
    std::set<int> validTypes = {1, 2};

    public :
    // constructor
    Foobar();
    // getters
    // the [[nodiscard]] serves for catching logical errors. If we ask for the bloomfilter we must use it!
    [[nodiscard]] const BloomFilter &getBloomFilter() const;
    // other methods
    static BloomFilter searchBloomFilter(std::istream &input);
    std::unique_ptr<ICommandable> getCommand(std::istringstream& iss);
    void run(std::istream &input);
    // bool isValid(int type);
};

#endif // BLOOMFILTER_FOOBAR_H