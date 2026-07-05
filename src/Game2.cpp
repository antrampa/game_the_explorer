#include "Game2.h"
#include "Utils.h"
#include <iostream>

Game2::Game2(std::string name) : 
    name(name) 
{}

Game2::~Game2() {
    // Destructor implementation (if needed)
}

void Game2::printGameLogo() {

    std::cout << "####################################################################################" << "\n";
    std::cout << "#                                                                                  #" << "\n";
    std::cout << "#   #        #   ############  ##             ####        ##########  ###########  #" << "\n";
    std::cout << "#    #      #    ##        ##  ##           ##    ##      ##       #   #    #  ##  #" << "\n";
    std::cout << "#     #    #     ##        ##  ##         ##        ##    ##        #  #     # ##  #" << "\n";
    std::cout << "#      #  #      ##        ##  ##       ##            ##  ##       #   #    #  ##  #" << "\n";
    std::cout << "#       ##       ############  ##     ##                # #########  ############  #" << "\n";
    std::cout << "#      #  #      ##            ##       ##             ## ##     #     #   #   ##  #" << "\n";
    std::cout << "#     #    #     ##            ##         ##         ##   ##      #    #    #  ##  #" << "\n";
    std::cout << "#    #      #    ##            ##           ##     ##     ##       #   #      ###  #" << "\n";
    std::cout << "#   #        #   ##            ##########     ####        ##        #############  #" << "\n";
    std::cout << "#                                                                                  #" << "\n";
    std::cout << "####################################################################################" << "\n";
    

}

bool Game2::startGame() {
    bool gameContinue = true;
    int menuChoice;
    do{
        menuChoice = printGameMenu();

        if(menuChoice == 1) {
            playTheGame();
        }
        else if(menuChoice == 2) {
            loadSavedGame();
        }
        else if(menuChoice == 3) {
            //end game
            gameContinue = false;
        }
    } while(gameContinue);

    return false;
}

int Game2::printGameMenu() {
    std::cout << "# Choose your option:        #" << "\n";
    std::cout << "#    1. Play the Game        #" << "\n";
    std::cout << "#    2. Load Saved Game      #" << "\n";
    std::cout << "#    3. Exit                 #" << "\n";

    int choice;
    //std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
        case 2:
        case 3:
            return choice;
        default:
            Utils::clearScreen();
            std::cout << "Invalid choice. Please try again." << std::endl;
            return printGameMenu(); 
    }
}

int Game2::playTheGame() {
    Utils::clearScreen();
    std::cout << "# Play the game #" << "\n";
    return 0;
} 

int Game2::loadSavedGame(){
    Utils::clearScreen();
    std::cout << "# Load saved game #" << "\n";
    return 0;
}