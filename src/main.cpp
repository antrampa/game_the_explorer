#include <iostream>
#include <string>
#include <limits>

#include "Animal.h"
#include "Player.h"
#include "City.h"
#include "CityKastoria.h"
#include "Game.h"
using namespace std; 

std::string cities[3] = {"KASTORIA", "FLORINA", "SERRES"};
int progress_city = 0;

void clearScreen();
void main_menu();
int savingTheGame();
int quiteFromTheGame();
void spaceBig();
int playInCity(City &city);
// int city_kastoria();
int city_kastoria(CityKastoria *kastoria);
int choose_city(int progress);
void startFightMessage();
void fight(Animal animal); 
void retreat(Animal animal);
void pressKey();
void continueFight(Animal animal);
void youAreDead(Animal animal);
void moveOn();
void goNextCity();

Player player("RandomPlayer1", 500, 10, 0, "Hands");

Player *player1 = new Player("RandomPlayer1Pointer", 500, 10, 0, "Hands");
Game game("EXPlORER", &player);

int main() {
    clearScreen();
    game.start();

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void main_menu() {
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
        case 0: {
            //city_kastoria();

            std::vector<Animal> animalsKastorias = { 
                Animal("Duck", 20, 2, 5, 1, 100),
                Animal("Dog", 30, 3, 10, 2, 200), 
                Animal("Cat", 40, 4, 15, 3, 300)
            };
            CityKastoria cityKastoria("KASTORIA", animalsKastorias);
            playInCity(cityKastoria);
             break;  // 👈 add break
        }  // 👈 add closing brace
        // default:
        //      quiteFromTheGame();   
    }
    return 0;
}

int playInCity(City &city) {
    clearScreen();
    city.showWelcomeMessage();
    pressKey();
    if (dynamic_cast<CityKastoria*>(&city)) {
        cout << "[DEBUG] You are in Kastoria City\n";
        //city_kastoria();
        CityKastoria *kastoria = dynamic_cast<CityKastoria*>(&city);
        city_kastoria(kastoria);

    } else {
        cout << "This city is not implemented yet.\n";
    }
    return 0;   

}

int city_kastoria(CityKastoria *kastoria) {
    clearScreen();
    kastoria->enterKastoria();
    pressKey();
    

    // cout << "       You are in the gate of the City         " << "\n";
    // cout << "                    KASTORIA                   " << "\n";
    // cout << "                                               " << "\n";
    // cout << "            You can enter, have fights         " << "\n";
    // cout << "        Earn golds, XP, HP and Reputation      " << "\n";
    // //spaceBig();
    // pressKey();
    // cout << "      You are in Enydreio in Ntailaki Area     " << "\n";
    // cout << "              An Animal is facing you          " << "\n";
    // //spaceBig();
    // pressKey();
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
    player.takeDamage(damage);
    player.checkStatus();
    if( player.isAlive() ) {
        continueFight(animal);
    } else {
        youAreDead(animal);
    }
    cout << "Do you want to continue fight or want ? retreat (f/r)";
} 

void retreat(Animal animal) {
    cout << ">I cann't face this " << animal.getName() << "\n";
    cout << ">Maybe another time little man!" << "\n\n";
}

void pressKey() {
    std::cout << "\n(Press Enter to continue...)\n\n";
    std::cin.clear(); // clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //,'\n'
    std::cin.get();   // wait for Enter
    std::cin.clear(); // clear error flags
}

void continueFight(Animal animal) {
    cout << "Do you want to continue fight or want ? retreat (f/r)";
    //cout << "You want to fight or retreat ? (f/r)";
    char ch;
    cin >> ch;
    ch = std::tolower(ch);
    if(ch == 'f') {
        int damage = player.attack();
        pressKey();
        animal.takeDamage(damage);
        animal.checkStatus();
        if(animal.isDead()) {
            cout << "!!!! VICTORY !!!!" << endl;
            cout << "You killed the " << animal.getName() << "\n";
            player.whatYouGot(animal.getName(), animal.getGold(), animal.getXpToGive(), animal.getHealthToGive());
            player.takeEverything(animal.getHealthToGive(), animal.getXpToGive(), animal.getGold());
            player.showStats();
            moveOn();
            //goNextCity();
        } else {
            pressKey();
            int damage = animal.attack();
            pressKey();
            player.takeDamage(damage);
            player.checkStatus();
            if( player.isAlive() ) {
                continueFight(animal);
            } else {
                youAreDead(animal);
            }
        }
    } else {
        retreat(animal);
    }
}

void youAreDead(Animal animal) {
    cout << "********* You Are DEAD lille Bro "<< player.getName() << "********************" << "\n\n";
    cout << "********* The Great  "<< animal.getName() << " killed you with his great power!" << "\n\n";
    cout << "  Your Total GOALD is: " << player.getGold() << "\n\n";
}

void moveOn() {
    cout << "**** Move On *******" << "\n\n";
    cout << "  Do you want to move on? (y/n)" << "\n";
    char ch;
    cin >> ch;
    ch = std::tolower(ch);
    if(ch == 'y') {
        goNextCity();
    } else {

    }
}

void goNextCity() {
    cout << "**** Go to the Next City *******" << "\n\n";
    //player.showStats();
    progress_city++;
    cout << "The city in front of you is " << cities[progress_city] << "\n";
    cout << "Do you want to enter ? (y/n)" << "\n";
}