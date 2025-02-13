#include "BloomFilter.h"


// constructor:
/**
 * constructor. At first call to Foobar (from main), bloomfilter gets initialized with default values.
 * @param tableSize - the size of the HashTable (all bits are initially set to 0)
 * @param hashTypes - the set of ints that represent the different types of hash functions,
   as given at initialization as well as later on by the set method.
 */
BloomFilter::BloomFilter(int tableSize, const std::set<int> &hashTypes)
    : HashTable(tableSize, 0), HashTypes(hashTypes), HashMap() {}
    
// getters:
std::vector<int> &BloomFilter::getHashTable()
{
    return HashTable;
}

std::map<std::string, std::set<int>> &BloomFilter::getHashMap()
{
    return HashMap;
}

std::set<int> &BloomFilter::getHashTypes()
{
    return HashTypes;
}

// other methods:
/** 
 * This method gets a url and runs it through a specific hash func
   (as declared by param hashType), it returns the location to search for in the hashTable.
 * @param url - to check if blacklisted.
 * @param hashType - the type of hashFunc to run.
 * @return int location to search.
 */

 // at each iteration, url is updated to be the string representation of the output of the last std::hash.
 // eventually we return the location based on the final output and the size of the current table (modulo).
int BloomFilter::runHash(std::string url, int hashType)
{
    size_t val;
    std::hash<std::string> hashFunction;
    // As per definition, hash func of type 1 should run once, type 2 twice and so on.
    // therefore, the condition rule, along with i = 0 works for any given hashfunc type.
    for (int i = 0; i < hashType; ++i)
    {
        // store the hashfunc output
        val = std::abs(static_cast<int>(hashFunction(url)));
        // convert output to string for next iteration
        url = std::to_string(val);
    }
    // preform modulo to find location
    return val % getHashTable().size();
}

/**
 * This method gets a url and runs all available hashFuncs to check whether or not its blacklisted.
   in case of multiple hashFuncs, all locations returned from all hashFuncs should be set to 1,
   in order for us to return true.
 * @param url - to check if blacklisted.
 * @return - true (is blacklisted) or false (isn't blacklisted).
 */

// my base assumption is that we only get to this method if hashTypes > 0 .
// if and only if, all locations of all hashFuncs are set to 1, then we will return true.
// proof: false & (true || false) - > false.
bool BloomFilter::checkBlacklist(std::string url)
{
    bool ans = true;
    for (int hashType : getHashTypes())
    {
        ans = ans and getHashTable()[runHash(url, hashType)] == 1;
    }
    return ans;
}

/**
 * this method gets a url and adds it to the blacklist by performing two operations:
   1. setting its location bit in the HashTable to 1 (according to hash results)
   2. adding <url, locations> of this url accordingly to HashMap
 * @param url
 */
void BloomFilter::addToBlacklist(std::string url)
{
    std::set<int> locations = {};
    for (int hashType : getHashTypes())
    {
        int location = runHash(url, hashType);
        // setting correct bits to 1
        getHashTable()[location] = 1;
        locations.insert(location);
    }
    // inserting to map
    getHashMap().insert(std::make_pair(url, locations));
}

/**
 * this method eliminates false positives, by searching for the specified url in HashMap
   that contains, by definition only blacklisted urls.
   If after searching for the url in the map we received a pointer to the end of the map,
   then we know that the url is not there, and therefore return false, vice versa.
 * @param url
 * @return true/false accordingly.
 */
bool BloomFilter::verify(std::string url)
{
    return getHashMap().find(url) != getHashMap().end();
}