#include "Animal.h"
#include <iostream>
#include <random>
using namespace std;

Animal::Animal() {}
Animal::Animal(std::string n, int h, int hPower, int hp, int xp, int g){
        name = n;
        health = h;
        hitPower = hPower;
        healthToGive = hp;
        xpToGive = xp;
        gold = g;
}

void Animal::introduce() {
    cout << "> Hi, I'm the " << name << " and my max power is " << hitPower << " \n";
    cout << "  My health is " << health << ". You can't destroy me small man" << " \n";
    cout << "  If you so, I'll give you " << xpToGive << "XP, " << healthToGive << "HP and " << gold << " GOLD " << " \n";
    cout << "\n";
}

string Animal::getName() {
    return name;
}

int Animal::randomAttack(int min, int max){
    std::random_device rd;  // seed
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

int Animal::attack(){
    cout << "> Me, THE " << name << "\n will attack you now with all my power of " << hitPower << "XP\n";
    int ap = randomAttack(hitPower/2, hitPower);
    cout << "The " << name << " attacked with " << ap << "XP\n";
    return ap;
}

int Animal::takeDamage(int damage){
    cout << "The " << name << " got damage of " << damage << "XP\n";
    health -= damage;
    return health;
}

int Animal::checkStatus(){
    cout << "The current health is: " << health << "HP\n";
    return health;
}

bool Animal::isDead() {
    return health > 0 ? false : true;
}

int Animal::getHealthToGive() {
    return healthToGive;
}

int Animal::getXpToGive() {
    return xpToGive;
}

int Animal::getGold() {
    return gold;
}
