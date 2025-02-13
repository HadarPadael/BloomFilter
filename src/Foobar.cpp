#include "Foobar.h"

// constructor:
/**
 This method uses searchBloomFilter for initializing bf.
 it waits for the searchBloomFilter to return an initialized bf.
 */
Foobar::Foobar()
    : bf(searchBloomFilter()){}

// getter:
/**
 * Getter for bloomFilter
 * @return the bloomFilter.
 */
const BloomFilter &Foobar::getBloomFilter() const
{
    return bf;
}

// other methods:
/**
 * This method loops infinitely. It reads every new input line and processes it.
   If its structured like an initialization line, then it initializes a new bloomfilter accordingly.
   Otherwise, it ignores it by returning an empty BloomFilter.
 * @return BloomFilter, as initialized by user.
 */
// TO DO: extract dependency! (input source and hashTypes)
BloomFilter Foobar::searchBloomFilter()
{
    std::string line;
    int size, temp;
    std::set<int> hashTypes;
    // taking input line by line
    while (std::getline(std::cin, line))
    {
        // reading the line as a stream
        std::istringstream iss(line);
        // the first value should be an int > 0, as it represents the size of the HashTable
        if ((iss >> size) && size > 0)
        {
            // checking if nums after the first val (hashTable size) are all valid hashTypes.
            while ((iss >> temp) && (temp == 1 || temp == 2))
            {
                hashTypes.insert(temp);
                // if the end of the string has been reached - return new BloomFilter.
                if (iss.eof())
                {
                    return BloomFilter(size, hashTypes);
                }
            }
            // if an unvalid hashtype was found, clear hashTypes set and wait for a new line.
            hashTypes.clear();
        }
    }

    return BloomFilter(0, {});
}

/**
 This method reads input lines, validates them according to specific requirements,
 processes valid inputs to set up a bloom filter,
 and continues until all input lines are processed or until an invalid input is encountered.
 */
// TO DO: extract dependency!! (hashTypes, number of urls per operation, operation type)
void Foobar::run()
{
    BloomFilter bloomFilter = getBloomFilter(); // TO DO: check that bloomfilter is not 0!!
    std::string line, url;
    int operation;
    // take input line by line
    while (std::getline(std::cin, line))
    {
        // read line as a stream
        std::istringstream iss(line);
        // if the first value id a valid operation, operate accordingly
        if ((iss >> operation) && operation >= 1 && operation <= 2)
        {
            // if the second val is of type str and is also the last one in the line, operate.
            if ((iss >> url) && iss.eof())
            {
                switch (operation)
                {
                case 1:
                    bloomFilter.addToBlacklist(url);
                    break;
                case 2:
                    bool isBlacklisted = bloomFilter.checkBlacklist(url);
                    std::cout << printOut(isBlacklisted);
                    if (isBlacklisted)
                    {
                        std::cout << " " << printOut(bloomFilter.verify(url));
                    }
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }
}

std::string Foobar::printOut(bool isBlacklisted)
{
    if (isBlacklisted == 1)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}