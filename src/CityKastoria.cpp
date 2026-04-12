#include "CityKastoria.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

CityKastoria::CityKastoria(std::string name, std::vector<Animal> animals) 
    : City(name) 
{
    this->animals = animals;
}