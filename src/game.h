#pragma once
#include <vector>
#include "town.h"
#include "player.h"

class Game
{
private:
    // Members
    vector<Town> towns;
    Player player;
    int active_town = 0;

    // Functions
    void handle_base_command(string command);

public:
    // Constructor
    Game();

    // Functions
    void print_status();
    void print_help();
    void run();
    string get_command();
};