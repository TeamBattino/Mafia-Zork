#include "game.h"
#include <iostream>

Game::Game()
{
    std::cout << "Game Constructor" << std::endl;
}

void Game::run()
{
    std::cout << "Game Running" << std::endl;
    std::cout << "Player Gold: " << playerGold << std::endl;
}