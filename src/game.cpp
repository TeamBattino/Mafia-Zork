#include "game.h"
#include <iostream>
#include <sstream>

Game::Game()
{
    cout << "Default Game Constructor" << endl;
    towns.push_back(Town("Town1", 100));
    towns.push_back(Town("Town2", 200));
    towns.push_back(Town("Town3", 300));
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
    string command;
    cout << "\033[1;32m❯ \033[0m";
    cin >> command;
    // split the command at " " into a vector<String>
    vector<string> command_vec = splitCommand(command);
    handle_command(command_vec);
}

vector<string> Game::splitCommand(const string &command)
{
    vector<string> result;
    stringstream ss(command);
    string word;

    while (ss >> word)
    {
        result.push_back(word);
    }

    return result;
}

void Game::handle_command(const vector<string> &command_vec)
{
    const string command = command_vec[0];
    if (command.compare("quit") == 0)
    {
        exit(0);
    }
    else if (command.compare("stats") == 0)
    {
        print_status();
    }
    else if (command.compare("balance") == 0)
    {
        printBalance();
    }
    else
    {
        cout << "Invalid Command" << endl;
    }
}

// Print Functions
void Game::printBalance()
{
    cout << "Player balance: " << player.get_balance() << endl;
}

void Game::print_status()
{
    cout << "Player balance: " << player.get_balance() << endl;
    cout << towns[active_town].name << " Population: " << towns[active_town].population << endl;
    cout << towns[active_town].name << " Local Reputation: " << towns[active_town].reputation << endl;
    cout << towns[active_town].name << " Cyndicate Influence: " << towns[active_town].influence << endl;
}