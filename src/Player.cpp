#include "Player.h"
#include <iostream>
#include <random>
using namespace std;

// std::string name_;
//         int health_;
//         int hitPower_;
//         int gold_;
//         std::string weapon_;

Player::Player(std::string name,int health, int hitPower, int gold, std::string weapon) : 
                name_(name), health_(health), hitPower_(hitPower), gold_(gold), weapon_(weapon)
{
}

// Player::Player(std::string n,int h, int hPower, int g) {
//     name = n;
//     health = h;
//     hitPower = hPower;
//     gold = g;
//     weapon = "<hands>";
// }

void Player::introduce(){
    cout << "\n";
    cout << "> Hello there, I'm " << name_ << " and my max power is " << hitPower_ << "XP \n";
    cout << "  My health is " << health_ << "HP. I will destroy you with my " << weapon_ << " and take your gold." << " \n";
    cout << "  No-one will remember you " << "\n";
    cout << "\n";
}   

void Player::setName(std::string name){
    name_ = name;
}

std::string Player::getName(){
    return name_;
}

int Player::randomAttack(int min, int max){
    std::random_device rd;  // seed
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

int Player::attack(){
    cout << "> Me, " << name_ << "\n will attack you now with all my power of " << hitPower_ << "XP\n";
    int ap = randomAttack(hitPower_/2, hitPower_);
    cout << "You attacked with " << ap << "XP\n";
    return ap;
}

int Player::takeDamage(int damage){
    cout << "You got a damage of " << damage << "XP. \n";
    health_ -= damage;
    cout << "Your remaining health is " << health_ << "HP \n";
    return health_;
}

int Player::checkStatus(){
    cout << "Your current health " << health_ << "HP \n";
    return health_;
}

bool Player::isAlive(){
    return health_ > 0;
}

int Player::getGold(){
    return gold_;
}

int Player::takeGold(int g){
    gold_ += g;
    return gold_;
}

int Player::takeEverything(int health, int hitPower, int gold){
    health_ += health;
    hitPower_ += hitPower;
    gold_ += gold;
    return gold_;
}

int Player::showStats() {
    cout << "You now have " << "\n";
    cout << "- Gold: " << gold_ << "\n"; 
    cout << "- Power: " << hitPower_ << "\n";
    cout << "- Health: " << health_ << "\n";
    cout << "- Weapon: " << weapon_ << "\n";
    return 0;
}

int Player::whatYouGot(std::string name, int gold, int hitPower, int health) {
    cout << "You got from " << name << "\n";
    cout << "- Gold: " << gold << "\n"; 
    cout << "- Power: " << hitPower << "\n";
    cout << "- Health: " << health << "\n";
    return 0;
}