#include <string>

class IHashable {
    public:
        // pure virtual so that any sub-class has to implement it on its own
        virtual int hashUrl(std::string url) const = 0;
        // destructor for propper cleanup
        virtual ~IHashable() {}

};