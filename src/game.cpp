#include "game.h"
#include <iostream>

Game::Game()
{
    std::cout << "Default Game Constructor" << std::endl;
    this->towns = [ new Town("small Town", 50), new Town("medium Town", 100), new Town("City", 500) ];
}

void Game::run()
{
    std::cout << "Game Running" << std::endl;
}

void Game::handleCommand(std::string command)
{
    std::cout << "Game Handling Command: " << command << std::endl;
}