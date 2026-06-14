#pragma once

#include <string>

class City {
    private:
        std::string name;

    public: 
        virtual ~City() = default;
        City(std::string name);
        std::string getName();
        virtual int showWelcomeMessage();
        virtual int play() = 0; //TODO REMOVE
        void clearScreen(); 
        void pressKey();
};