#include "BloomFilter.h"
#include "ICommandable.h"

class SearchCommand : public ICommandable {
    public:

        SearchCommand(BloomFilter bloom, std::string url) : bloom(bloom), url(url) {}

        void execute() override {
            //check if the url is blacklisted according to hashTable
            bool isBlacklisted = bloom.checkBlacklist(url);
            std::cout << printOut(isBlacklisted);
            // check whether its a false positive, using the hashMap
            if (isBlacklisted) {
                std::cout << " " << printOut(bloom.verify(url));
            }
            std::cout << std::endl;
        }

    private:

    BloomFilter bloom;
    std::string url;
    // a method that comverts 1 and 0 to true and false accordingly.
    std::string printOut(bool isBlacklisted) {
        if (isBlacklisted == 1) {
            return "true";
        } else {
            return "false";
        }
    }
};