#include "look-n-say.h"
#include <iostream>

int main() {
    printlist<look_and_say<8>::t>::print(std::cout);
    return 0;
}
