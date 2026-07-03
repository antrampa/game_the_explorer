#include "Utils.h"

#include <iostream>

void Utils::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Utils::pressKey() {
    std::cout << "Press any key to continue.../\n";
    std::cin.ignore();
    std::cin.get();
}