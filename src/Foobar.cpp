#include "Foobar.h"
#include "SearchCommand.cpp"
#include "AddCommand.cpp"
#include "ICommandable.h"
#include <memory>

// constructor:
/**
 This method uses searchBloomFilter for initializing bf.
 it waits for the searchBloomFilter to return an initialized bf.
 */
Foobar::Foobar()
    : bf(searchBloomFilter(std::cin)) {}

// getter:
/**
 * Getter for bloomFilter
 * @return the bloomFilter.
 */
const BloomFilter &Foobar::getBloomFilter() const {
    return bf;
}

// other methods:
// bool Foobar::isValid(int type) {
//     if(validTypes.find(type) != validTypes.end()) {
//         return true;
//     } 
//     return false;
// }
/**
 * This method loops infinitely. It reads every new input line and processes it.
   If its structured like an initialization line, then it initializes a new bloomfilter accordingly.
   Otherwise, it ignores it by returning an empty BloomFilter.
 * @return BloomFilter, as initialized by user.
 */
BloomFilter Foobar::searchBloomFilter(std::istream &input)
{
    std::string line;
    int size, temp;
    std::set<int> hashTypes;
    // taking input line by line
    while (std::getline(input, line))
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
 This method reads input lines from the user and acts upon valid command lines.
 1 - add to blacklist
 2 - check if blacklisted.
 */
void Foobar::run(std::istream &input)
{
    std::string line; 
    // take input line by line
    while (std::getline(input, line)) {
        // read line as a stream
        std::istringstream iss(line);
        // check if there's a command to execute
        std::unique_ptr<ICommandable> command = getCommand(iss);
        // run the command
        if (command) { 
            command->execute(); 
        }
    }
}

std::unique_ptr<ICommandable> Foobar::getCommand(std::istringstream& iss)
{
    std::string url;
    int operation;
    // if the first value id a valid operation, operate accordingly
    if ((iss >> operation) && operation >= 1 && operation <= 2)
    {
        // if the second val is of type str and is also the last one in the line, operate.
        if ((iss >> url) && iss.eof())
        {
            switch (operation) {
            case 1:
                return std::make_unique<AddCommand>(&bf, url);
            case 2:
                return std::make_unique<SearchCommand>(bf, url);
            }
        }
    }
    return nullptr;
}
