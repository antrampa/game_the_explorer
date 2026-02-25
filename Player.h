#pragma once

#include <string>

class Player {

    private:
        std::string name;
        int health;
        int hitPower;
        int gold;

    public:
        Player(std::string name,int health, int hitPower, int gold);
        void introduce();     
        void setName(std::string n);         
        std::string getName();
        int randomAttack(int min, int max);
        int attack();
        int getDamage(int damage);
        int checkStatus();
        bool isAlive();
        int getGold();

};