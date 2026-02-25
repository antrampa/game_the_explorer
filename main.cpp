#include <iostream>
#include <string>
#include <limits>

#include "Animal.h"
#include "Player.h"
using namespace std; 

 std::string cities[3] = {"KASTORIA", "FLORINA", "SERRES"};

void main_menu();
int savingTheGame();
int quiteFromTheGame();
void spaceBig();
int city_kastoria();
int choose_city(int progress);
void startFightMessage();
void fight(Animal animal); 
void retreat(Animal animal);
void pressKey();

Player player("RandomPlayer1", 500, 10, 0);

int main() {
    cout << "########         THE EXPlORER          ########" << "\n";
    cout << "######## The Game EXPlORER is starting ########" << "\n";
    //Get players name
    main_menu();

    return 0;
}

void main_menu() {
    int progress_city = 0;
    char choose;
    cout << "###############################################" << "\n";
    cout << "########            Main menu          ########" << "\n";
    cout << "########             GREECE            ########" << "\n";
    cout << "###############################################" << "\n\n";
    cout << "######## The Game EXPlORER is starting ########" << "\n";
    cout << "###############################################" << "\n";
    cout << "The city in front of you is " << cities[progress_city] << "\n";
    cout << "Do you want to enter ? (y/n)" << "\n";
    cin >> choose;
    choose = std::tolower(choose);
    
    if (choose == 'y') {
        choose_city(progress_city);
    } else if (choose == 'n') {
        cout << "You chose no.\n";
        savingTheGame();
        quiteFromTheGame();
    } else {
        cout << "Invalid input.\n";
        main_menu();
    }
    
    //std::basic_ostream<char, std::char_traits<char>>
    // & operator<<<std::char_traits<char>>(std::ostream &_Ostr, const char *_Val)

}


int savingTheGame() {
    cout << "Test saving!";

    return 0;
}

int quiteFromTheGame() {
    cout << "Save and quite.. chicken!!\n";
    cout << "Ko..ko ko KO KO KO>.\n";
    cout << "Bye chicken!\n";
    return 0;
}

void spaceBig() {
    cout << "\n\n\n";
}

int choose_city(int progress) {
    switch(progress) {
        case 0:
            city_kastoria();
        // default:
        //      quiteFromTheGame();   
    }
    return 0;
}

int city_kastoria() {
    cout << "       You are in the gate of the City         " << "\n";
    cout << "                    KASTORIA                   " << "\n";
    cout << "                                               " << "\n";
    cout << "            You can enter, have fights         " << "\n";
    cout << "        Earn golds, XP, HP and Reputation      " << "\n";
    spaceBig();
    pressKey();
    cout << "      You are in Enydreio in Ntailaki Area     " << "\n";
    cout << "              An Animal is facing you          " << "\n";
    spaceBig();
    pressKey();
    Animal an1("Duck", 20, 2, 5, 1, 100);
    an1.introduce();
    cout << "You want to fight or retreat ? (f/r)";
    char ch;
    cin >> ch;
    ch = std::tolower(ch);
    if(ch == 'f') {
        player.introduce();
        pressKey();
        fight(an1);
    } else {
        retreat(an1);
    }

    return 0;
}

void startFightMessage() {
    cout << "!!!! Fight is starting !!!!" << "\n\n";
    cout << "   Good luck lille bro " << "\n\n";
}

void fight(Animal animal) {
    startFightMessage();
    pressKey();
    int damage = animal.attack();
    pressKey();
    player.getDamage(damage);
} 

void retreat(Animal animal) {
    cout << ">I cann't face this " << animal.getName() << "\n";
    cout << ">Maybe another time little man!" << "\n\n";
}

void pressKey() {
    std::cout << "\n(Press Enter to continue...)\n\n";
    std::cin.clear(); // clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();   // wait for Enter
}