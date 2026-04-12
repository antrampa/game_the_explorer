#pragma once

#include <string>

class Player {

    private:
        std::string name;
        int health;
        int hitPower;
        int gold;
        std::string weapon;

    public:
        Player(std::string name,int health, int hitPower, int gold);
        void introduce();     
        void setName(std::string n);         
        std::string getName();
        int randomAttack(int min, int max);
        int attack();
        int takeDamage(int damage);
        int checkStatus();
        bool isAlive();
        int getGold();
        int takeGold(int gold);
        int takeEverything(int hp, int xp, int gold);
        int showStats();
        int whatYouGot(std::string name, int hp, int xp, int g);
};