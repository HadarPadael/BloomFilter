#include "../IHashable.h"

class HashRepetition : public IHashable {
    public:
        //constructor
        HashRepetition(int repNum, int size) : repNum(repNum), size(size) {}
        // override father class

        // at each iteration, url is updated to be the string representation of the output of the last std::hash.
        // eventually we return the location based on the final output and the size of the current table (modulo).
        int hashUrl(std::string url) const override {
            // As per definition, hash func of type 1 should run once, type 2 twice and so on.
            // therefore, the condition rule, along with i = 0 works for any given hashfunc type.
            for (int i = 0; i < repNum; ++i) {
                // store the hashfunc output
                val = hashFunction(url);
                // convert output to string for next iteration
                url = std::to_string(val);
            }
            // preform modulo to find location
            return val % size;
        }

    private:
        int repNum;
        int size;
        // has to be mutable so that it could be overwritten in every iteration of a const override
        mutable size_t val;
        std::hash<std::string> hashFunction;
};