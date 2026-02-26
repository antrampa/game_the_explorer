#include "Player.h"
#include <iostream>
#include <random>
using namespace std;

Player::Player(std::string n,int h, int hPower, int g) {
    name = n;
    health = h;
    hitPower = hPower;
    gold = g;
}

void Player::introduce(){
    cout << "\n";
    cout << "> Hello there, I'm " << name << " and my max power is " << hitPower << "XP \n";
    cout << "  My health is " << health << "HP. I will destroy you and take your gold." << " \n";
    cout << "  No one will remember you " << "\n";
    cout << "\n";
}   

void Player::setName(std::string n){
    name = n;
}

std::string Player::getName(){
    return name;
}

int Player::randomAttack(int min, int max){
    std::random_device rd;  // seed
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

int Player::attack(){
    cout << "> Me, " << name << "\n will attack you now with all my power of " << hitPower << "XP\n";
    int ap = randomAttack(hitPower/2, hitPower);
    cout << "You attacked with " << ap << "XP\n";
    return ap;
}

int Player::takeDamage(int damage){
    cout << "You got a damage of " << damage << "XP. \n";
    health -= damage;
    cout << "Your remaining health is " << health << "HP \n";
    return health;
}

int Player::checkStatus(){
    cout << "Your current health " << health << "HP \n";
    return health;
}

bool Player::isAlive(){
    return health > 0;
}

int Player::getGold(){
    return gold;
}

int Player::takeGold(int g){
    gold += g;
    return gold;
}

int Player::takeEverything(int hp, int xp, int g){
    gold += g;
    return gold;
}

int Player::showStats() {

    return 0;
}