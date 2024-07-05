#pragma once
#include <vector>
#include "town.h"
#include "player.h"
#include "drug.h"
#include <string>
class Game
{
private:
    // Members
    vector<Town> towns;
    Player player;
    int active_town = 0;

    // Functions
    // Print Functions
    bool random_by_chance(int chance);

    void handle_base_command(string command);

public:
    // Constructor
    Game();

    // Functions
    void process_round();
    void print_status();
    void print_help();
    void run();
    string get_command();
    void recruit();
    void recruit_bribe(int amount);
    void recruit_force();
};