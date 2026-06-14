#include "City.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

City::City(std::string name)
{
    this->name = name;
}

int City::showWelcomeMessage(){
    cout << "       You are in the gate of the City         " << "\n";
    cout << "                    "<< this->name  << "                   " << "\n";
    cout << "                                               " << "\n";
    cout << "            You can enter, have fights         " << "\n";
    cout << "        Earn golds, XP, HP and Reputation      " << "\n";
    // //spaceBig();
    // //pressKey();
    // cout << "      You are in Enydreio in Ntailaki Area     " << "\n";
    // cout << "              An Animal is facing you          " << "\n";
    // //spaceBig();
    // pressKey();
    // //Animal an1("Duck", 20, 2, 5, 1, 100);
    // an1.introduce();
    // cout << "You want to fight or retreat ? (f/r)";
    // char ch;
    // cin >> ch;
    // ch = std::tolower(ch);
    // if(ch == 'f') {
    //     player.introduce();
    //     pressKey();
    //     fight(an1);
    // } else {
    //     retreat(an1);
    // }

    return 0;
}

int City::play() {
    cout << "This city is not implemented yet.\n";
    return 0;
}

void City::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void City::pressKey() {
    std::cout << "\n(Press Enter to continue...)\n\n";
    std::cin.clear(); // clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //,'\n'
    std::cin.get();   // wait for Enter
    std::cin.clear(); // clear error flags
}