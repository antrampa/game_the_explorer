#pragma once

#include "Player.h"
#include <string>

class Game {
    private:
        std::string name;
        Player *player;
        int status; // 0: not started, 1: in progress, 2: completed
        bool isGameOver;
        bool isPlayerWins;
        int currentLevel;
        int score;
        int progressCity;

    public:
        Game(std::string name);
        Game(std::string name, Player *player);
        ~Game();
        int play();
};