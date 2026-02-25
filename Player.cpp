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
    return 0;
}

int Player::attack(){
    return 0;
}

int Player::getDamage(int damage){
    return 0;
}

int Player::checkStatus(){
    return 0;
}

bool Player::isAlive(){
    return 0;
}

int Player::getGold(){

    return 0;
}