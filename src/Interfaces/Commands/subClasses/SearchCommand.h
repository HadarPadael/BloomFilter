#include "../ICommandable.h"
#include "../../../BloomFilter/BloomFilter.h"
#include "../../IOChannels/IOutputChannel.h"

#include <memory>
#include <string>

class SearchCommand : public ICommandable {
    public:
        // Inject both the BloomFilter, URL, and the output channel dependency.
        SearchCommand(BloomFilter bloom, const std::string &url, IOutputChannel &output)
            : bloom(bloom), url(url), output(output) {}

        void execute() override {
            bool isBlacklisted = bloom.checkBlacklist(url);
            // Instead of std::cout, use the output channel
            output.write(printOut(isBlacklisted));

            if (isBlacklisted) {
                output.write(" " + printOut(bloom.verify(url)));
            }
            output.write("\n");
        }

    private:

    BloomFilter bloom;
    std::string url;
    IOutputChannel &output; 

    // Helper method that converts bool to string
    std::string printOut(bool isBlacklisted)
    {
        return isBlacklisted ? "true" : "false";
    }
};