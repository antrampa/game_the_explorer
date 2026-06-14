#include "CityKastoria.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

CityKastoria::CityKastoria(std::string name, std::vector<Animal> animals) 
    : City(name), animals(animals)
{
    this->animals = animals;
}

int CityKastoria::enterKastoria() {

    cout << "      You are in Enydreio in Ntailaki Area     " << "\n";
    cout << "              An Animal is facing you          " << "\n";

    return 0;
}

int CityKastoria::play() {
    // clearScreen();
    // enterKastoria();
    // pressKey();
    firstAnimal();

    // cout << "You want to fight or retreat ? (f/r)";
    // char ch;
    // cin >> ch;
    // ch = std::tolower(ch);
    // if(ch == 'f') {
    //     player.introduce();
    //     pressKey();
    //     fight(an1);
    // } else {
    //     retreat(an1);
    // }
    return 0;
}

int CityKastoria::firstAnimal() {
    Animal animal = animals[0];
    animal.introduce();
    return 0;
}