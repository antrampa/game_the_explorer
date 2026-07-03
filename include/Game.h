#pragma once

#include "Player.h"
#include "CityKastoria.h"
#include "Animal.h"

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
        std::string cities[3] = {"KASTORIA", "FLORINA", "SERRES"};
        int progress_city;

    public:
        Game(std::string name);
        Game(std::string name, Player *player);
        ~Game();
        void printGameLogo();
        int start();
        void clearScreen();
        void pressKey();
        void main_menu();
        int play();
        int savingTheGame();
        int quiteFromTheGame();
        void startFightMessage();
        int fight(Animal animal);
        void retreat(Animal animal);  
        int choose_city(int progress);
        int playInCityKastoria(CityKastoria *kastoria);
};