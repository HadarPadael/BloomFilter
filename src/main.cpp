#include "Foobar/Foobar.h"
#include "Interfaces/IOChannels/subClasses/ConsoleInputChannel.h"
#include "Interfaces/IOChannels/subClasses/ConsoleOutputChannel.h"

int main() {
    ConsoleInputChannel input(std::cin);
    ConsoleOutputChannel output;

    Foobar foo(input, output);
    foo.run();

    return 0;
}