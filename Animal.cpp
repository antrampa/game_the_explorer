#include <iostream>
using namespace std;

class Animal {
    private:
        string name;
        int health;
        int hitPower;
        int healthToGive;
        int xpToGive;
        int gold;
    
    public:
        void introduce() {
            cout << "Hi, I'm the " << name << " and my max power is " << hitPower << " \n";
            cout << "My health is " << health << ". You can't destroy me small man" << " \n";
            cout << "If you so, I'll give you " << xpToGive << "XP and " << gold << " GOLD " << " \n";
        }
};