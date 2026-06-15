#include "CityKastoria.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

CityKastoria::CityKastoria(std::string name) 
    : City(name), animals(animals)
{
    std::vector<Animal> animals = { 
                Animal("Duck", 20, 2, 5, 1, 100),
                Animal("Dog", 30, 3, 10, 2, 200), 
                Animal("Cat", 40, 4, 15, 3, 300)
            };
    this->animals = animals;
}

CityKastoria::CityKastoria(std::string name, std::vector<Animal> animals) 
    : City(name), animals(animals)
{
    this->animals = animals;
}

int CityKastoria::enterKastoria() {

    cout << "          You are in Kastoria Gates     " << "\n";
    cout << "       There are dangerous animals here          " << "\n";
    cout << " That means there are golds and opportunities          " << "\n";

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

Animal CityKastoria::firstAnimal() {
    Animal animal = animals[0];
    cout << "      You are in Enydreio in Ntailaki Area     " << "\n";
    cout << "              An Animal is facing you          " << "\n";
    animal.introduce();
    return animal;
}

Animal CityKastoria::getAnimal(int number) {
    Animal animal = animals[number];
    animal.introduce();
    return animal;
}