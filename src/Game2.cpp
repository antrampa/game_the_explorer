#include "Game2.h"

#include <iostream>

Game2::Game2(std::string name) : 
    name(name) 
{}

Game2::~Game2() {
    // Destructor implementation (if needed)
}

void Game2::printGameLogo() {
    std::cout << "###############################################" << "\n";
    std::cout << "########            Game 2             ########" << "\n";
    std::cout << "########             GREECE            ########" << "\n";
    std::cout << "###############################################" << "\n\n";
}