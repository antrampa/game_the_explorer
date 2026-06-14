#include "Game.h"
#include "Player.h"
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
}

Game::~Game() {
    // Destructor implementation (if needed)
}

int Game::play() {
    cout << "Game is starting...\n";
    // Implement the game logic here
    return 0;
}