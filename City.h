#pragma once

#include <string>

class City {
    private:
        std::string name;

    public: 
        City(std::string name);
        std::string getName();
};