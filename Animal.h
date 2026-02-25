#ifndef ANIMAL_H
#define ANIMAL_H
//#pragma once

#include <string>

class Animal {
    private:
        std::string name;
        int health;
        int hitPower;
        int healthToGive;
        int xpToGive;
        int gold;

    public:
        Animal(std::string n, int health, int hitPower, int healthToGive, int xpToGive, int gold);  // Constructor
        void introduce();              // Method
        std::string getName();
        int randomAttack(int min, int max);
        int attack();
        int getDamage(int damage);
        int checkStatus();
        bool isDead();
};

#endif