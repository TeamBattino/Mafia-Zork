#include "game.h"
#include <iostream>

Game::Game()
{
    cout << "Default Game Constructor" << std::endl;
    towns.push_back(Town("Town1", 100));
    towns.push_back(Town("Town2", 200));
    towns.push_back(Town("Town3", 300));
    player = Player();
    active_town = 0;
}

void Game::run()
{
    while (true)
    {
        get_command();
    }
}

void Game::get_command()
{
    std::string command;
    cout << "\033[1;32m❯ \033[0m";
    std::cin >> command;
    handle_command(&command);
}

void Game::handle_command(std::string *command)
{
    if (command->compare("quit") == 0)
    {
        exit(0);
    }
    else if (command->compare("stats") == 0)
    {
        print_status();
    }
    else if (command->compare("balance") == 0)
    {
        printBalance();
    }
    else
    {
        std::cout << "Invalid Command" << std::endl;
    }
}

// Print Functions
void Game::printBalance()
{
    cout << "Player balance: " << player.get_balance() << std::endl;
}

void Game::print_status()
{
    cout << "Player balance: " << player.get_balance() << std::endl;
    cout << towns[active_town].name << " Population: " << towns[active_town].population << std::endl;
    cout << towns[active_town].name << " Local Reputation: " << towns[active_town].reputation << std::endl;
    cout << towns[active_town].name << " Cyndicate Influence: " << towns[active_town].influence << std::endl;
}