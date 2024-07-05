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
    else if (command->compare("recruit") == 0)
    {
        recruit();
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

void Game::recruit()
{
    if (random_by_chance(towns[active_town].reputation / 2))
    {
        towns[active_town].recruits++;
        cout << "Amount of recruits: " << towns[active_town].recruits << endl;
    }
    else
    {
        string bribe_choice;
        cout >> "Do you want to try and bribe him?" >> endl;
        cin << bribe_choice;

        if(bribe_choice.choice("y")){
            recruit_bribe(101);
        }
    }
}

bool Game::random_by_chance(int chance)
{
    srand((unsigned)time(0));

    auto test = (rand() % 100) < (chance);
    cout << test << endl;
    return test;
}

void Game::recruit_bribe(int amount)
{
    if (amount >= player.get_balance())
    {
        if (random_by_chance(towns[active_town].reputation / 2))
        {
            player.set_balance(-amount);
            towns[active_town].reputation++;
            towns[active_town].recruits++;

            cout << "Amount of recruits: " << towns[active_town].recruits << endl;
        }
        else
        {
            towns[active_town].reputation--;

            string force_choice;
            cout << "Looks like hes not corrupt. Do you want to force him? (y/n)";
            cin >> force_choice;

            if (force_choice.compare("y") == 0)
            {
                recruit_force();
                towns[active_town].recruits++;
            }
        }
    }
    else
    {
        cout << 'Youre broke.' << endl;
    }
}

void Game::recruit_force()
{
    towns[active_town].reputation++;
    towns[active_town].influence--;
}
