#include "ICommandable.h"
#include "BloomFilter.h"
#include <string>

class AddCommand : public ICommandable {
    public:
    //constructor
    AddCommand(BloomFilter* bloom, std::string url) : bloom(bloom), url(url) {}
    void execute() override {
        bloom->addToBlacklist(url);
    }

    private:
    BloomFilter* bloom;
    std::string url;
};