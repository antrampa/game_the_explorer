#pragma once

namespace Utils {
 
    inline void clearScreen() {
       #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    inline void pressKey() {
        std::cout << "Press any key to continue.../\n";
        std::cin.ignore();
        std::cin.get();
    }
}