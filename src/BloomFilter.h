#ifndef EXC1_BLOOMFILTER_H
#define EXC1_BLOOMFILTER_H

#include <iostream>
#include <vector>
#include <set>
#include <map>

class BloomFilter
{
private:
    // The actual bit array, in which every cell is a location set to either 1 or 0
    std::vector<int> HashTable;
    // A map for all blacklisted urls. Will be used to check for false positives.
    std::map<std::string, std::set<int>> HashMap;
    // The variables that store the type of hashfunction used
    std::set<int> HashTypes;

public:
    // constructor for the bloomfilter
    BloomFilter(int tableSize, const std::set<int> &hashTypes);
    // Getters for members
    std::vector<int> &getHashTable();
    std::map<std::string, std::set<int>> &getHashMap();
    std::set<int> &getHashTypes();
    // other methods
    int runHash(std::string url, int hashType);
    bool checkBlacklist(std::string url);
    void addToBlacklist(std::string url);
    bool verify(std::string url);
};

#endif // EXC1_BLOOMFILTER_H