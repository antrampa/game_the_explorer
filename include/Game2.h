#pragma once
#include <iostream>

class Game2 {
    private:
        std::string name;
        

    public:
        Game2(std::string name);
        ~Game2();
        void printGameLogo();
        bool startGame();
        int printGameMenu();
        int playTheGame(); 
        int loadSavedGame();
};
