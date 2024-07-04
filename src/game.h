#pragma once
#include <vector>
#include "town.h"
#include "player.h"

class Game
{
private:
    // Members
    std::vector<Town> towns;
    Player player;
    int active_town = 0;

    // Functions
    void handle_command(string *command);
    // Print Functions
    void printBalance();

public:
    // Constructor
    Game();
    // Functions
    void print_status();
    void run();
    void get_command();
};