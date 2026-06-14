#pragma once

#include <string>
#include <vector>
#include "City.h"
#include "Animal.h"

class CityKastoria : public City {
    private:
        std::string var1;
        Animal animal;
        std::vector<Animal> animals;

    public: 
        CityKastoria(std::string name, std::vector<Animal> animals);
        Animal getAnimal();
        std::vector<Animal> getAnimals();
        int enterKastoria();
        int introOfCity();
        int play() override; //TODO REMOVE
        int firstAnimal();
        int secondAnimal();
        int thirdAAnimal();
        int thirdBnimal();
        int finalAnimal();
        
};