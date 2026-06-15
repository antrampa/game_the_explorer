#include "Game.h"
#include "Animal.h"
#include "Player.h"
#include "City.h"
#include "CityKastoria.h"

#include <iostream>
#include <random>
using namespace std;



Game::Game(std::string name) : Game(name, new Player("RandomPlayer1", 500, 10, 0)) { }

Game::Game(string name, Player *player) {
    this->name = name;
    this->player = player;
    this->status = 1; // 0: not started, 1: in progress, 2: completed
    this->isGameOver = false;
    this->isPlayerWins = false;
    this->currentLevel = 1;
    this->score = 0;
    this->progressCity = 0;

    //this->cities[3] = {"KASTORIA", "FLORINA", "SERRES"};
    this->progress_city = 0;

}

Game::~Game() {
    // Destructor implementation (if needed)
}

int Game::start() {
    clearScreen();
    // Implement the game logic here
    cout << "########         THE EXPlORER          ########" << "\n";
    cout << "######## The Game EXPlORER is starting ########" << "\n";
    main_menu();

    return 0;
}


void Game::main_menu() {
    
    cout << "###############################################" << "\n";
    cout << "########            Main menu          ########" << "\n";
    cout << "########             GREECE            ########" << "\n";
    cout << "###############################################" << "\n\n";
    cout << "######## The Game EXPlORER is starting ########" << "\n";
    cout << "###############################################" << "\n";
    //TODO : Add more menu options and logic here
    char choose;
    cout << "Choole your option: " << "\n";
    cout << "   1. Play the Game" << "\n";
    cout << "   2. Load Saved Game" << "\n";
    cout << "   3. Exit" << "\n";
    cin >> choose;
    choose = std::tolower(choose);

    if(choose == '1'){
        clearScreen();
        play();
    } else if(choose == '2') {
        clearScreen();
        cout << "Load Saved Game option selected." << "\n";
    } else if (choose == '3') {        
        clearScreen();    
        cout << "Exit option selected." << "\n";
        isGameOver = true;
    } else {
        clearScreen();
        cout << "Invalid input. Please choose a valid option." << "\n";
        main_menu();
    }
    
}

int Game::play() {

    while (!isGameOver) {        
        char choose;
        cout << "The city in front of you is " << cities[progressCity] << "\n";
        cout << "Do you want to enter ? (y/n) [Y]" << "\n";
        cin >> choose;
        choose = std::tolower(choose);

         if (choose != 'n') {
            cout << "progressCity:" << progressCity << endl;
            choose_city(progressCity);
        } else if (choose == 'n') { //TODO: Check for other options
            cout << "You chose no.\n";
            savingTheGame();
            quiteFromTheGame();
            main_menu();
        } else {
            cout << "Invalid input.\n";
            main_menu();
        }
        
        // Game loop logic
        // For example, you can check the player's status, handle events, etc.
        if (!player->isAlive()) {
            isGameOver = true;
            cout << "Game Over! You have been defeated." << endl;
            break;
        } else if (progressCity >= sizeof(cities) / sizeof(cities[0])) {
            isGameOver = true;
            isPlayerWins = true;
            cout << "Congratulations! You have completed the game." << endl;
            break;
        }

        // Additional game logic can be added here
    }
    
    
   

    return 0;
}

void Game::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int Game::savingTheGame() {
    cout << "Test saving!";

    return 0;
}

int Game::quiteFromTheGame() {
    isGameOver = true;
    cout << "Save and quite.. chicken!!\n";
    cout << "Ko..ko ko KO KO KO>.\n";
    cout << "Bye chicken!\n";
    return 0;
}

int Game::choose_city(int progress) {
    switch(progress) {
        case 0: {
            cout << "City Kastoria!!" << endl;
            
            CityKastoria cityKastoria("KASTORIA");
            playInCityKastoria(&cityKastoria);
             break;  
        }  
        // default:
        //      quiteFromTheGame();   
    }
    return 0;
}


int Game::playInCityKastoria(CityKastoria *kastoria) {
    clearScreen();
    kastoria->enterKastoria();
    pressKey();
    clearScreen();
    Animal an1 = kastoria->firstAnimal();
    bool playerRetreat = false;
    do {
        cout << "You want to fight or retreat ? (f/r) " << endl;
        char ch;
        cin >> ch;
        ch = std::tolower(ch);
        if(ch == 'f') {
            clearScreen();
            this->player->introduce();
            pressKey();
            clearScreen();
            fight(an1);
        } else {
            retreat(an1);
            playerRetreat = true;
        }
    } while (this->player->isAlive() && an1.isDead() == false && playerRetreat == false);

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
    
    
    // Animal an1("Duck", 20, 2, 5, 1, 100);
    // an1.introduce();
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

void Game::pressKey() { 
    std::cout << "\n(Press Enter to continue...)\n\n";
    std::cin.clear(); // clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //,'\n'
    std::cin.get();   // wait for Enter
    std::cin.clear(); // clear error flags
}


void Game::startFightMessage() {
    cout << "!!!! Fight is starting !!!!" << "\n\n";
    cout << "   Good luck lille bro " << "\n\n";
}

int Game::fight(Animal animal) {
    startFightMessage();
    pressKey();
    clearScreen();
    int damage = animal.attack();
    pressKey();
    clearScreen();
    player->takeDamage(damage);
    player->checkStatus();
    cout << endl << "Do you want to continue fight or want ? retreat (f/r) " << endl;
    return 0;
} 

void Game::retreat(Animal animal) {
    cout << ">I cann't face this " << animal.getName() << "\n";
    cout << ">Maybe another time little man!" << "\n\n";
}