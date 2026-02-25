#include <iostream>
#include <string>

//#include "Animal.h"
using namespace std; 

 std::string cities[3] = {"KASTORIA", "FLORINA", "SERRES"};

void main_menu();
int savingTheGame();
int quiteFromTheGame();
int city_kastoria();
int choose_city(int progress);


int main() {
    cout << "########         THE EXPlORER          ########" << "\n";
    cout << "######## The Game EXPlORER is starting ########" << "\n";

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
    
    if (choose == 'y' || choose == 'yes') {
        choose_city(progress_city);
    } else if (choose == 'n' || choose == 'no') {
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

    return 0;
}