#include <iostream>
#include <string>
#include <limits>

#include "Game2.h"
#include "Utils.h"
using namespace std; 


int main() {
    Utils::clearScreen();
    Game2 game2("THE ExPlORER");
    game2.printGameLogo();

    return 0;
}
