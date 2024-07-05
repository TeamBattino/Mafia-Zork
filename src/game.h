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
    bool random_by_chance(int chance);
    

public:
    // Constructor
    Game();
    // Functions
    void print_status();
    void run();
    void get_command();
    void recruit();
    void recruit_bribe(int amount);
    void recruit_force();
};