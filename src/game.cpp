#include "game.h"
#include <iostream>

using namespace std;

Game::Game()
{
    cout << "Default Game Constructor" << std::endl;
    towns = vector<Town>(new Town("Town1", 100), new Town("Town2", 200), new Town("Town3", 300));
    player = Player();
    active_town = 0;
}

void Game::run()
{
    std::cout << "Game Running" << std::endl;
}
